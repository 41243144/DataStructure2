/*
    寫一完整C++程式implement quick sort並分析其時間複雜度。
*/
#include <iostream>

using namespace std;

class QuickSort
{
private:
	int *arr;
public:
	QuickSort(int arr[])
	{
		this->arr = arr;
	}
	void quickSort(int arr[], int left, int right)
	{
		if (left >= right) return;
		int i = left - 1;
		int pivot = arr[right];

		for (int j = left; j < right; j++)
		{
			if (arr[j] < pivot)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}

		swap(arr[i + 1], arr[right]);
		quickSort(arr, left, i);
		quickSort(arr, i + 2, right);
	}

	void printArray(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int* randomArray(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	return arr;
}

int main()
{
	int size = 10;
	int* arr = randomArray(size);

	QuickSort quickSort(arr);
	cout << "初始化陣列: ";
	quickSort.printArray(arr, size);

	quickSort.quickSort(arr, 0, size - 1);
	cout << "排序後陣列: ";
	quickSort.printArray(arr, size);

}