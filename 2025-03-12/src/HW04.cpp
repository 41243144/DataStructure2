/*
    寫一完整C++程式implement merge sort，分析其時間複雜度並證明其為optimal algorithm。
*/
#include <iostream>

using namespace std;

class MergeSort {
private:
    int* arr;
    int size;

public:
    MergeSort(int arr[], int size) {
        this->arr = arr;
        this->size  = size;
    }

    void printArray() {
		//cout << size << endl;
        for (int i = 0; i < size; i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << arr[i];
        }
        cout << endl;
    }

    void merge(int left, int mid, int right) {
        int arr_length_1 = mid - left + 1;
        int arr_length_2 = right - mid;

        int *arr1 = new int[arr_length_1];
        int* arr2 = new int[arr_length_2];

        for (int i = 0; i < arr_length_1; i++) {
            arr1[i] = arr[left + i];
        }

        for (int i = 0; i < arr_length_2; i++) {
            arr2[i] = arr[mid + i + 1];
        }

        int i = 0, j = 0, k = left;


        while (i < arr_length_1 && j < arr_length_2) {
            if (arr1[i] < arr2[j]) {
                arr[k] = arr1[i];
                i++;
            }
            else {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < arr_length_1) {
            arr[k] = arr1[i];
            i++;
            k++;
        }

        while (j < arr_length_2) {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);

    }
};

int main()
{
    int arr[10] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 9 };
    int size = 10;

    MergeSort obj(arr, size);
    obj.printArray();

    obj.mergeSort(0, size - 1);
    obj.printArray();

    system("pause");
	return 0;
}
