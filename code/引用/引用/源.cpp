#include<iostream>

using namespace std;

class myclass {
public:
	//���캯��
	myclass(int size = 0) :bag_size(size) {
		cout << "this is my bag" << endl;

		bag = new int[size];
	}
	//�������캯��
	myclass(myclass& oldclass) {
		cout << "this is new class" << endl;

		bag = new int[oldclass.bag_size];

	}
	//��ֵ����
	myclass& operator=(myclass& oldclass) {
		cout << "operator =" << endl;

		if (this == &oldclass) {
			return *this;
		}

		delete[] bag;

		bag_size = oldclass.bag_size;
		bag = new int[bag_size];
	}
	//��������
	~myclass() {
		cout << "delete myclass" << endl;
		delete[] bag;
		bag = nullptr;
	}

private:
	int* bag;
	int bag_size;
};

int main() {
	myclass check1(10);

	myclass check2(check1);

	myclass check3 ;

	check3 = check2;

	system("pause");
}