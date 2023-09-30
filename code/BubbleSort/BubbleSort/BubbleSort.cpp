#include<iostream>
using namespace std;

void BubbleSort(int* arr, int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 1,9,3,7,4,2,8,4,0 };
    int arr_size = sizeof(arr) / sizeof(int);

    BubbleSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i];
    }
}