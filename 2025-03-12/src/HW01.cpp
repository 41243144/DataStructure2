/*
	給定數列: 60, 24,15, 11, 2, 77,1,19, 89, 91 
	使用下列各種排序演算法進行由小到大排序 (以下各子題請直接寫出答案，不須寫處理過程) 
	(a) 請寫出Bubble sort 第一個回合之後的排序結果； 
	(b) 請寫出Insertion sort 第一個回合之後的排序結果； 
	(c) 請寫出Selection sort 第一個回合之後的排序結果； 
	(d) 請寫出Quick sort 第一個回合之後的排序結果。 
*/
#include <iostream>

using namespace std;

class Sort
{
private:
	int* arr;
	int size;

public:
	Sort(int* arr, int size)
	{
		this->arr = arr;
		this->size = size;
	}

	/*---------------輸出陣列---------------*/
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	/*---------------泡沫排序---------------*/
	void bubbleSort()
	{
		/*
			利用泡沫排序法，將陣列中的元素由小到大排序
		*/
		for (int i = 0; i < size - 1; i++)
		{
			if (i == 1) {
				cout << "第一個回合之後的排序結果: ";
				print();
			}
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	/*---------------選擇排序---------------*/
	void selectionSort()
	{
		/*
			利用選擇排序法，將陣列中的元素由小到大排序
		*/
		for (int i = 0; i < size - 1; i++)
		{
			if (i == 1) {
				cout << "第一個回合之後的排序結果: ";
				print();
			}
			int min = i;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[min])
				{
					min = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	/*---------------插入排序---------------*/
	void insertionSort()
	{
		/*
			利用插入排序法，將陣列中的元素由小到大排序
		*/
		for (int i = 1; i < size; i++)
		{
			if (i == 2) {
				cout << "第一個回合之後的排序結果: ";
				print();
			}
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	/*---------------快速排序---------------*/
	void quickSort(int left, int right, bool isFirstCall = true) {
		/*
			利用快速排序法，將陣列中的元素由小到大排序
            使用陣列最右邊的值作為pivot
		*/


		if (left >= right)
			return;

		int i = left - 1;

		for (int j = left; j < right; j++)
		{
			if (arr[j] < arr[right])
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}

		swap(arr[i + 1], arr[right]);

		if (isFirstCall == true)
		{
			cout << "第一個回合之後的排序結果: ";
			print();
			isFirstCall = false;
		}

		quickSort(left, i, isFirstCall);
		quickSort(i + 2, right, isFirstCall);
	}
};

int main()
{
    int arr1[] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 91 };
    int arr2[] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 91 };
    int arr3[] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 91 };
    int arr4[] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 91 };

    int size = sizeof(arr1) / sizeof(arr1[0]);

    Sort BubbleSort(arr1, size);
    Sort InsertionSort(arr2, size);
    Sort SelectionSort(arr3, size);
    Sort QuickSort(arr4, size);

	cout << "-----------------------Bubble Sort-----------------------" << endl;
	cout << "原始陣列: ";
	BubbleSort.print();
	BubbleSort.bubbleSort();
	cout << "經過Bubble Sort排序後: ";
	BubbleSort.print();

	cout << "-----------------------Insertion Sort-----------------------" << endl;
	cout << "原始陣列: ";
	InsertionSort.print();
	InsertionSort.insertionSort();
	cout << "經過Insertion Sort排序後: ";
	InsertionSort.print();

	cout << "-----------------------Selection Sort-----------------------" << endl;
	cout << "原始陣列: ";
	SelectionSort.print();
	SelectionSort.selectionSort();
	cout << "經過Selection Sort排序後: ";
	SelectionSort.print();

	cout << "-----------------------Quick Sort-----------------------" << endl;
	cout << "原始陣列: ";
	QuickSort.print();
	QuickSort.quickSort(0, size - 1);
	cout << "經過Quick Sort排序後: ";
	QuickSort.print();
}