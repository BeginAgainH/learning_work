#include<iostream>
#include<thread>
using namespace std;

class test {
public:
	test(int n = 0) {
		num = n;
		cout << "No." << num << " has been created!!!" << " The dest is" << this << endl;
	}

	void helloclass() {
		cout << "No." << num << endl;
	}

	int testnum() {
		return num;
	}

	test(const test& tmp) :num(tmp.num) {
		cout << "deep copy has done!!!" << endl;
		cout << this << " copys " << &tmp <<" and No is "<< tmp.num<< endl;
	}

	~test() {
		
		cout << "No." << num << "`s dest is"<<this<<" and has been deleted!!!" << endl;
	}

	

private:
	int num;
};

void check(int i = 1) {
	if (i != 1) {
		
		for (int j = 0; j < i; j++) {
			thread listh(&test::helloclass,test(j));
			listh.join();
		}
	}
	else {
		//test deftest;

		thread myth(&test::helloclass, test());
		myth.join();
	}
}

void prt0()
{
	cout << "normal class thread and this thread is " << this_thread::get_id()<< endl;
}

void prt1(test tmp)
{
	cout << "normal class thread and this thread is " << this_thread::get_id() << " the class is " << tmp.testnum() <<" and dest is "<<&tmp<< endl;
}


void prt3(test&& tmp) {
	cout << "this thread is " << this_thread::get_id() << " and use right cite, the class is " << tmp.testnum() << " and dest is " << &tmp << endl;
}

void prt4(test& tmp) {
	cout << "this thread is " << this_thread::get_id() << " and use left cite, the class is " << tmp.testnum() << " and dest is " << &tmp << endl;
}


int main() {

	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:{
			thread myth0(prt0);
			myth0.join();
			cout << endl;
			break;}

		case 1:{
			thread myth1(prt1,test(i));
			myth1.join();
			cout << endl;
			break;}

		case 2:{
			auto auptr = [](test tmp) {
				cout << "this thread is " << this_thread::get_id() << " and use lambda, the class is " << tmp.testnum() << " and dest is " << &tmp << endl;
			};
			thread myth2(auptr,test(i));
			myth2.join();
			cout << endl;
			break;}

		case 3:{
			thread myth3(prt3,move(test(3)));
			myth3.join();
			cout << endl;
			break;}
		
		case 4: {
			test mytest4(i);
			thread myth4(prt4, ref(mytest4));
			myth4.join();
			cout << endl;
			break;
		}
		}
	}
}