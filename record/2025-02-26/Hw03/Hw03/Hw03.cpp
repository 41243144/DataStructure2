// Hw03.cpp

#include <iostream>

using namespace std;


// Tail recursion
int Tail(int* arr, int currentMaxValue, int arrLength) {
	// 如果陣列長度為0，則回傳目前最大值
	if (arrLength == 0) {
		return currentMaxValue;
	}
	else {
		// 如果最後一個元素大於目前最大值，則更新目前最大值
		if (arr[arrLength - 1] > currentMaxValue) {
			currentMaxValue = arr[arrLength - 1];
		}
		// 遞迴呼叫，將陣列長度減1
		return Tail(arr, currentMaxValue, arrLength - 1);
	}
}

// Divide and conquer
int divide(int* arr, int arrLength) {
	// 如果陣列長度為1，則回傳陣列第一個元素
	if (arrLength == 1) {
		return arr[0];
	}
	else {
		// 分成兩半，分別呼叫divide函數
		int left = divide(arr, arrLength / 2);
		int right = divide(arr + arrLength / 2, arrLength - arrLength / 2);
		// 回傳兩半中的最大值
		if (left > right) {
			return left;
		}
		else {
			return right;
		}
	}
}

int main()
{
	int arr[] = { 58, 95, 16, 38, 38, 65, 73, 78, 0, 46 };

	cout << "Tail: " << Tail(arr, arr[0], sizeof(arr) / sizeof(arr[0])) << endl;
	cout << "Divide: " << divide(arr, sizeof(arr) / sizeof(arr[0])) << endl;
}
