#include<iostream>

using namespace std;

int main() {
	int num1 = 1;
	int num2 = 2;

	int* ptr1[] = { &num1,&num2 };

	int arr1[] = {1,2,3};
	int arr2[] = { 4,5,6 };
	int arr3[][3] = {{1,2,3},{ 4,5,6 }};


	int(*ptr2)[2] ;
	ptr2  = (int (*)[2])arr3;

	cout << "ptr1 size: " << sizeof(ptr1) << endl;
	cout << "ptr2 size: " << sizeof(ptr2) << endl;
	cout << "arr1 size: " << sizeof(arr1) << endl;
	cout << "arr3 size: " << sizeof(arr3) << endl;
	
}