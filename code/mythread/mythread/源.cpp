#include<iostream>
#include<thread>
#include<string>

using namespace std;

class m {
public:
	m(int n = 100) :no(n) {
		cout << "No." << no << "is created" << "dest is" << this << endl;
	}

	m(const m& oldm) {
		this->no = oldm.no;
		cout << "new class has been copy and dest is"<<this << endl;
	}

	~m() {

		cout << "No." << no << "is deleted" << this << endl;
	}
private:
	int no;
};

void myprint(int n,char* buffer) {
	cout << n <<endl;
	cout << "const`s dest in thread is:"<<&n << endl;

	cout << buffer << endl;
	cout << "buffer`s dest in thread is: " << &buffer << endl;
}

void myclass(const int n,const m &mclass) {
	cout << n << endl;
	cout << "const`s dest in thread is:" << &n << endl;

	cout <<  "class` dest is" << &mclass << endl;
}



int main() {
	//普通参数
	/*int var = 1;
	int& myvar = var;
	char buffer[] = "hello world!!!";
	cout << "const`s dest is:" <<&myvar<< endl;
	cout << "buffer`s dest is : " << &buffer << endl;

	thread mythread1(myprint, var, buffer);
	mythread1.join();

	cout << "const`s dest is:" << &myvar << endl;
	cout << "buffer`s dest is : " << &buffer << endl;*/

	//自定义对象作为参数
	int num;
	cin >> num;
	int& cinnum = num;
	
	cout << "const`s dest is:" << cinnum << endl;

	thread mythread2(myclass, cinnum, m(2));
	mythread2.join();
	
}