#include<iostream>
#include<thread>
using namespace std;

class myclass {
public:
	myclass() {
		cout << "normall construction and the dest is " << this << endl;
		num = 0;
	}

	myclass(int i) {
		cout << "parament construction and the dest is " << this << endl;
	}

	myclass(const myclass& temp):num(temp.num) {
		cout << "deep copy has done and " << this << " copys " << &temp << endl;
	}

	~myclass() {
		cout << this << " has been deleted" << endl;
	}


private:
	int num;
};

class basec {
public:
	basec() {
		cout << "create base class" << endl;
	}

	virtual void printb() {
		cout << "this is base class" << endl;
	}

	 virtual ~basec() {
		cout << "delete base class" << endl;
	}
};

class derivec :public basec {
public:
	derivec() {
		cout << "create derive class" << endl;
	}

	

	~derivec() {
		cout << "delete derive class" << endl;
	}
};

void bd(basec* p) {
	p->printb();
}


void useclass1(myclass temp) {
	cout << " func1 use class and the class is " << &temp << endl;
}

void useclass2(const myclass &temp) {
	cout << " func2 use class by left cite and the class is " << &temp << endl;
}

void useclass3(myclass &&temp) {
	cout << " func3 use class by right cite and the class is " << &temp << endl;
}


int main() {
	//cout << "classes are creating" << endl;
	//myclass tempclass1;
	//myclass tempclass2(1);
	//myclass tempclass3(tempclass2);

	//cout << endl;

	///*cout << "use existing class" << endl;
	//useclass1(tempclass1);
	//useclass2(tempclass1);
	//useclass3(move(tempclass1));


	//cout << endl;

	//cout << "use temp class" << endl;
	//useclass1(myclass());
	//useclass2(myclass(1));
	//useclass3(myclass(1));*/

	//auto mybda1 = [](myclass temp) {
	//	cout << "use lambda and the dest is " << &temp << endl;
	//};
	//auto mybda2 = [](const myclass &temp) {
	//	cout << "use lambda by left cite and the dest is " << &temp << endl;
	//};
	//auto mybda3 = [](myclass &&temp) {
	//	cout << "use lambda by right cite and the dest is " << &temp << endl;
	//};

	//mybda1(tempclass1);
	//mybda2(tempclass1);
	//mybda3(move(tempclass1));

	//cout << endl;

	//mybda1(myclass(1));
	//mybda2(myclass(1));
	//mybda3(myclass(1));

	basec *basec1 = new basec;

	derivec *derivec1 = new derivec;

	bd(basec1);
	bd(derivec1);


	delete basec1;
	delete derivec1;
}