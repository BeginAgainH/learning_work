#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Calculate {
public:
	double num1;
	vector<string> mem;
	void jia() {
		double  num2;

		cout << "���������:" << endl;
		cin >> num2;

		ostringstream inser;

		inser << num1 << " + " << num2 << " = " << num1 + num2;	

		num1 += num2;
		cout << "���Ϊ:	" << num1 << endl;

		mem.push_back(inser.str());
	}
	void jian() {
		double  num2;

		cout << "���������:" << endl;
		cin >> num2;

		ostringstream inser;

		inser << num1 << " - " << num2 << " = " << num1 - num2;

		num1 -= num2;
		cout << "���Ϊ:	" << num1<< endl;


		mem.push_back(inser.str());

	}
	void cheng() {
		double  num2;

		cout << "���������:" << endl;
		cin >> num2;

		ostringstream inser;

		inser << num1 << " * " << num2 << " = " << num1 * num2;

		num1 *= num2;
		cout << "���Ϊ:	" << num1 << endl;

		mem.push_back(inser.str());
	}
	void chu() {
		double  num2;

		cout << "���������:" << endl;
		cin >> num2;

		ostringstream inser;

		inser << num1 << " / " << num2 << " = " << num1 / num2;
		
		num1 /= num2;
		cout << "���Ϊ:	" << num1<< endl;


		mem.push_back(inser.str());
	}
	void dao() {
		ostringstream inser;

		inser <<"1 / " << num1 <<" = " << 1 / num1;

		num1 = 1 / num1;

		cout << "���Ϊ:	" << num1 << endl;

		mem.push_back(inser.str());
	}
	void pin() {

		ostringstream inser;

		inser << num1 << " ^2 = " <<pow(num1,2);

		num1 *= num1;
		cout << num1 << "ƽ���Ľ��Ϊ:	" << num1  << endl;

		mem.push_back(inser.str());
	}
	void kai() {

		ostringstream inser;

		inser << num1 << " ^1/2 = " << sqrt(num1);

		num1 = sqrt(num1);
		cout << num1 << "�����Ľ��Ϊ:" << num1 << endl;


		mem.push_back(inser.str());
	}
	void cle() {
		mem.clear();
		cout << "�������,�����������һ����" << endl;
		cin >> num1;
	}
	void check() {
		for (vector<string>::iterator it = mem.begin(); it != mem.end(); it++) {
			cout << *it << endl;
		}
	}

};


int main() {

	while (1) {
		cout << "�������һ������" << endl;
		Calculate cal;
		int num;
		cin >> num;
		cal.num1 = num;
		int choice;
		while(1){
			cout << "������ѡ����:" << endl;
			
			cout << "1.�� 2.�� 3.�� 4.�� 5.ȡ���� 6.ƽ�� 7.���� 8.��ѯ��¼ 9.���� 0.�˳� " << endl;

			cin >> choice;
				switch(choice) {
				case 1:
					cal.jia();
					break;
				case 2:
					cal.jian();
					break;
				case 3:
					cal.cheng();
					break;
				case 4:
					cal.chu();
					break;
				case 5:
					cal.dao();
					break;
				case 6:
					cal.pin();
					break;
				case 7:
					cal.kai();
					break;
				case 8:
					cal.check();
					break;
				case 9:
					cal.cle();
					break;
				case 0:
					return 0;
		}
		}
	}
		
}