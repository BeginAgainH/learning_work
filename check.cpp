#include<iostream>
#include<functional>

int CheckData(int year, int month, int day) {
	return (1 + day + 2 * month + 3 * (month + 1) / 5 + year/4 - year/100 + year/400 + year) % 7;
}

int main() {
	int year, month, day;
	auto checkptr = std::bind(CheckData,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);

	std::cin >> year >> month >> day;


	std::cout << year << "年" << month << "月" << day << "日是星期" << checkptr(year, month, day) << std::endl;
}