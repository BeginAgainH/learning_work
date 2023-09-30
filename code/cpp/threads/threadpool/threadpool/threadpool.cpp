/*
	ʲô���̳߳أ��̳߳ؾ���һ������������У������̶߳��У�ÿ����һ������ͷ����һ���߳�ȥ����ѭ��������һ���������
	�ص���ʲô���̳߳�Ҫ�����̣߳��������ĳ���߳���������������������Ϊ������µ����񣬵����̵߳�����������������󶨵�
				����Ϊ�˽��������⣬����ÿ����һ���߳̾�ȥִ��һ�����Ⱥ������õ��Ⱥ���ѭ����ȡ����ִ��
	ѭ�������������̳߳ؽ���ʱѭ���ͽ����������ȱ�֤���̺߳�����Ψһ�ԣ�Ҳȷ���˸����߳�ִ������
	
	�̳߳���ɲ��֣�1���������		2���̳߳�
					�̳߳غ�������еĹ�ϵ�ǵ��͵�������-������ģ�ͣ�����Ӧ������п�ʱ���߳������ȴ��������µ�����ʱ��ѭ����ȡ
	ͬ���뻥�⣺1�����̻߳�ȡ�����ͬ����	2�������ȡ����ӵĻ�����

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
	���̳߳ص�ͬ���Ժͻ����Կ�֪,�̼߳�ͬ����ȡ����,������л����������
	�ʶ���������н��в���ʱ,����û�������֤�̶߳�������в�����Ψһ��,������ֻ��һ���߳��ڸ�ʱ���ܹ���������в���
	������ɺ�������������
	*/
	
	ThreadPool(int _nums) :stop(false) {
		//���캯��,����_nums��ʾ�����̵߳�����
		for (int i = 0; i < _nums; i++) {
			//ѭ�������߳�,�̴߳�����ִ��
			//ͨ��lambda���ʽ�����߳������õĺ���
			cout << "The " << i << "thread has been created" << endl;
			threads.emplace_back([this] {
				while (true) {
					//�߳�ִ�к���Ϊѭ����ȡ������
					unique_lock<mutex> lock(cv_m);
					condition.wait(lock, [this] {
					//���������Ϊ��,�������ȴ�,ֱ������������������
						if (!(stop || !tasks.empty())) cout << "Thread id " << this_thread::get_id() << " is waiting for the task" << endl;
						return stop || !tasks.empty();
						});
					//�߳̽������������Ϊ��ʱ,����ѭ��
					if (stop && tasks.empty()) {
						return;
					}
					//����Ϣ�����л�ȡ����
					cout << "Thread id " << this_thread::get_id() << " gets the task" << endl;
					function<void()> task(move(tasks.front()));
					tasks.pop();
					//��Ϣ���н���
					lock.unlock();
					//ִ������
					task();
				}
				});
		}
	}

	~ThreadPool() {
		//�����Ĵ����ű�ʾ������ʱ��������������
		{

			unique_lock<mutex>lock(cv_m);
			stop = true;
		}
		//���������ڵȴ����߳�
		condition.notify_all();
		//�����̳߳ز�ִ��
		for (thread& thread : threads) {
			thread.join();
		}
	}

	template<typename F,typename... Args>
	void enqueue(F&& f, Args&&... args) {
		//����������������
		//����ģ������ֵ����Ϊ��������,��������Ϊ��ֵ���þ�ȡ��ֵ����,��ֵ���þ�Ϊ��ֵ����
		function<void()> task(bind(forward<F>(f), forward<Args>(args)...));
		{
			//�����������
			unique_lock<mutex>lock(cv_m);
			tasks.emplace(move(task));
		}
		//�������������,�����ڵȴ���һ���߳�
		condition.notify_one();
	}

private:
	bool stop;	//�߳̽�����ʶ
	vector<thread>threads;	//�̳߳�
	queue<function<void()>> tasks;	//�������
	mutex mutx;	//������
	condition_variable condition;	//��������
};

int main() {
	//�����̳߳ض��󲢳�ʼ��,�߳̿�ʼ����,���ڴ�ʱ�������Ϊ��,�����ȴ����������
	ThreadPool pool(4);

	for (int i = 0; i < 8; i++) {
		//����������������
		pool.enqueue([i] {
			cout << "Task " << i << " is running in the thread " << this_thread::get_id() << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Task " << i << " is done" << endl;
			});
	}

	return 0;
}