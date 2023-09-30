#include<iostream>
#include <functional>
using namespace std;


#include <iostream>
class Base {
public:
	Base() {
	std:cout << 1 << std :: endl;
	}
	Base(Base&& other) {
	std:cout << 2 << std::endl;
	}
	Base(const Base& other) {
		std::cout << 3 << std::endl;
	}
	Base& operator= (Base&& other) {
	std:cout << 4 << std::endl;
		return *this;
	}
	Base& operator= (const Base& other) {
	std:cout << 5 << std::endl;
		return *this;
	};

};

char fun(char x, char y) {
	if (x < y)
		return x;
	return y;
}

int main(){
	int a = 2, b = 2, c = 2;
	printf("%d", a / b & c);
	}

