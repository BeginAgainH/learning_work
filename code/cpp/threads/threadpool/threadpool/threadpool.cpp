/*
	什么是线程池：线程池就是一个管理任务队列，管理线程队列，每次有一个任务就分配给一个线程去做，循环往复的一个处理机制
	重点是什么：线程池要复用线程，即分配给某个线程任务并在完成任务后再重新为其分配新的任务，但是线程的生命周期是与任务绑定的
				所以为了解决这个问题，可以每创建一个线程就去执行一个调度函数，该调度函数循环获取任务并执行
	循环结束条件：线程池结束时循环就结束，这样既保证了线程函数的唯一性，也确保了复用线程执行任务
	
	线程池组成部分：1、任务队列		2、线程池
					线程池和任务队列的关系是典型的生产者-消费者模型，当对应任务队列空时，线程阻塞等待，当有新的任务时，循环获取
	同步与互斥：1、多线程获取任务的同步性	2、任务获取和添加的互斥性

*/


#include<iostream>
#include<thread>
#include<vector>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<functional>

using namespace std;

mutex cv_m;

class ThreadPool {
public:
	/*
	由线程池的同步性和互斥性可知,线程间同步获取任务,任务队列互斥出入任务
	故而对任务队列进行操作时,需调用互斥锁保证线程对任务队列操作的唯一性,即有且只有一个线程在该时刻能够对任务队列操作
	操作完成后立马解除互斥锁
	*/
	
	ThreadPool(int _nums) :stop(false) {
		//构造函数,传入_nums表示创建线程的数量
		for (int i = 0; i < _nums; i++) {
			//循环创建线程,线程创建即执行
			//通过lambda表达式传入线程所调用的函数
			cout << "The " << i << "thread has been created" << endl;
			threads.emplace_back([this] {
				while (true) {
					//线程执行函数为循环获取任务函数
					unique_lock<mutex> lock(cv_m);
					condition.wait(lock, [this] {
					//若任务队列为空,则阻塞等待,直到有任务进入任务队列
						if (!(stop || !tasks.empty())) cout << "Thread id " << this_thread::get_id() << " is waiting for the task" << endl;
						return stop || !tasks.empty();
						});
					//线程结束且任务队列为空时,结束循环
					if (stop && tasks.empty()) {
						return;
					}
					//从消息队列中获取任务
					cout << "Thread id " << this_thread::get_id() << " gets the task" << endl;
					function<void()> task(move(tasks.front()));
					tasks.pop();
					//消息队列解锁
					lock.unlock();
					//执行任务
					task();
				}
				});
		}
	}

	~ThreadPool() {
		//单独的大括号表示里面临时变量的生命周期
		{

			unique_lock<mutex>lock(cv_m);
			stop = true;
		}
		//唤醒所有在等待的线程
		condition.notify_all();
		//遍历线程池并执行
		for (thread& thread : threads) {
			thread.join();
		}
	}

	template<typename F,typename... Args>
	void enqueue(F&& f, Args&&... args) {
		//往任务队列添加任务
		//函数模板里右值引用为万能引用,即传入若为左值引用就取左值引用,右值引用就为右值引用
		function<void()> task(bind(forward<F>(f), forward<Args>(args)...));
		{
			//互斥添加任务
			unique_lock<mutex>lock(cv_m);
			tasks.emplace(move(task));
		}
		//任务队列有任务,唤醒在等待的一个线程
		condition.notify_one();
	}

private:
	bool stop;	//线程结束标识
	vector<thread>threads;	//线程池
	queue<function<void()>> tasks;	//任务队列
	mutex mutx;	//互斥锁
	condition_variable condition;	//条件变量
};

int main() {
	//创建线程池对象并初始化,线程开始运行,由于此时任务队列为空,阻塞等待任务入队列
	ThreadPool pool(4);

	for (int i = 0; i < 8; i++) {
		//向任务队列添加任务
		pool.enqueue([i] {
			cout << "Task " << i << " is running in the thread " << this_thread::get_id() << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Task " << i << " is done" << endl;
			});
	}

	return 0;
}