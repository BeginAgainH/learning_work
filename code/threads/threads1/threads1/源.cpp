#include<iostream>
#include<vector>
#include<list>
#include<thread>
#include<mutex>

using namespace std;

//vector<int>argv = { 1,2,3 };//共享数据，只读

class msg {
public:
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000000; i++) {
			//插入消息元素
			
			cout << "inMsgRecQueue()执行，插入一个元素 " << i << endl;

			//thmutext.lock();//加锁
			lock_guard<mutex> guard(thmutext);

			msgRecvQueue.push_back(i);
			
			//thmutext.unlock();//解锁

		}
	}

	void outMsgRecQueue()
	{
		for (int i = 0; i < 100000000; i++)
		{
			//读取消息元素
			//thmutext.lock();
			lock_guard<mutex> guard(thmutext);
			if (!msgRecvQueue.empty()) {
				int cmd = msgRecvQueue.front();
				msgRecvQueue.pop_front();
				cout << "outMsgRecQueue()执行 " << i << endl;
			}
			else {
				cout << "outMsgRecQueue()执行，但目前消息队列为空 " << i << endl;
			}
			//thmutext.unlock();
		}

		cout << "end" << endl;
	}

private:
	list<int>msgRecvQueue; //容器，专门用于代表发送的命令

	mutex thmutext;//互斥锁，lock和unlock成对使用，必须一对一
};

void tprint1(int inum) {
	/*cout << "线程开始执行,线程编号: " << inum << endl;
	cout << "线程结束执行,线程编号: " << inum << endl;*/

	//cout << "线程id: " << this_thread::get_id() <<" 编号为: "<<inum << " 打印的值为 " << argv[0] << argv[1] << argv[2] << endl;
}

int main() {
	vector<thread> mythreads;

	//for (int i = 0; i < 10; i++) {
	//	//创建10个线程，入口函数统一tprint1
	//	mythreads.push_back(thread(tprint1,i));	//创建并开始执行线程
	//	
	//}
	//for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++) {
	//	iter->join();//等待10个线程都返回
	//}

	//cout << "结束线程运行" << endl;

	msg player;
	thread outMsgth(&msg::outMsgRecQueue, &player);
	thread inMsgth(&msg::inMsgRecQueue, &player);

	outMsgth.join();
	inMsgth.join();

	return 0;//进程退出

}
/*多线程管理问题*/
//1、由于操作系统内部对线程运行调度机制，故而线程执行顺序是混乱的
//2、主线程等待所有子线程执行完后再结束，更稳定
//3、线程对象放入容器管理，对于大量线程的管理操作很方便

/*数据共享问题*/
//1、只读数据无需额外操作，可多个线程同时读
//2、有读有写，通过互斥量(mutex)实现操作共享数据的互斥进行，使得读写操作稳定进行
//3、std::lock_guard直接取代lock和unlock，实现自动互斥，使用后不再可以用lock和unlock,因为lock_guard是一个类模板,创建时调用构造函数执行了lock，结束时调用析构函数执行unlock,故而保护对象必须在同一作用域内
//4、两个及以上的互斥量就会有死锁问题产生的可能