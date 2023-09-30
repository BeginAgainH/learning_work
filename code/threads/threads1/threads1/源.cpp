#include<iostream>
#include<vector>
#include<list>
#include<thread>
#include<mutex>

using namespace std;

//vector<int>argv = { 1,2,3 };//�������ݣ�ֻ��

class msg {
public:
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000000; i++) {
			//������ϢԪ��
			
			cout << "inMsgRecQueue()ִ�У�����һ��Ԫ�� " << i << endl;

			//thmutext.lock();//����
			lock_guard<mutex> guard(thmutext);

			msgRecvQueue.push_back(i);
			
			//thmutext.unlock();//����

		}
	}

	void outMsgRecQueue()
	{
		for (int i = 0; i < 100000000; i++)
		{
			//��ȡ��ϢԪ��
			//thmutext.lock();
			lock_guard<mutex> guard(thmutext);
			if (!msgRecvQueue.empty()) {
				int cmd = msgRecvQueue.front();
				msgRecvQueue.pop_front();
				cout << "outMsgRecQueue()ִ�� " << i << endl;
			}
			else {
				cout << "outMsgRecQueue()ִ�У���Ŀǰ��Ϣ����Ϊ�� " << i << endl;
			}
			//thmutext.unlock();
		}

		cout << "end" << endl;
	}

private:
	list<int>msgRecvQueue; //������ר�����ڴ����͵�����

	mutex thmutext;//��������lock��unlock�ɶ�ʹ�ã�����һ��һ
};

void tprint1(int inum) {
	/*cout << "�߳̿�ʼִ��,�̱߳��: " << inum << endl;
	cout << "�߳̽���ִ��,�̱߳��: " << inum << endl;*/

	//cout << "�߳�id: " << this_thread::get_id() <<" ���Ϊ: "<<inum << " ��ӡ��ֵΪ " << argv[0] << argv[1] << argv[2] << endl;
}

int main() {
	vector<thread> mythreads;

	//for (int i = 0; i < 10; i++) {
	//	//����10���̣߳���ں���ͳһtprint1
	//	mythreads.push_back(thread(tprint1,i));	//��������ʼִ���߳�
	//	
	//}
	//for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++) {
	//	iter->join();//�ȴ�10���̶߳�����
	//}

	//cout << "�����߳�����" << endl;

	msg player;
	thread outMsgth(&msg::outMsgRecQueue, &player);
	thread inMsgth(&msg::inMsgRecQueue, &player);

	outMsgth.join();
	inMsgth.join();

	return 0;//�����˳�

}
/*���̹߳�������*/
//1�����ڲ���ϵͳ�ڲ����߳����е��Ȼ��ƣ��ʶ��߳�ִ��˳���ǻ��ҵ�
//2�����̵߳ȴ��������߳�ִ������ٽ��������ȶ�
//3���̶߳�����������������ڴ����̵߳Ĺ�������ܷ���

/*���ݹ�������*/
//1��ֻ�������������������ɶ���߳�ͬʱ��
//2���ж���д��ͨ��������(mutex)ʵ�ֲ����������ݵĻ�����У�ʹ�ö�д�����ȶ�����
//3��std::lock_guardֱ��ȡ��lock��unlock��ʵ���Զ����⣬ʹ�ú��ٿ�����lock��unlock,��Ϊlock_guard��һ����ģ��,����ʱ���ù��캯��ִ����lock������ʱ������������ִ��unlock,�ʶ��������������ͬһ��������
//4�����������ϵĻ������ͻ���������������Ŀ���