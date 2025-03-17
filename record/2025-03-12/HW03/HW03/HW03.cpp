/*
    Stooge sort是一種 recursive排序法
    其演算法如下： 
        (1) 如果當前集合最後一個元素值小於第一個元素值，則交換此兩元素值 
        (2) 如果當前集合元素數量大於等於3時： 
            (a) 使用Stooge sort排序前 2/3的元素； 
            (b) 使用Stooge sort排序後 2/3的元素；  
            (c) 再次使用Stooge sort排序前 2/3的元素； 
        (3) 否則結束執行，返回函式呼叫處。 
    請寫一完整C++程式implement Stooge sort，並分析Stooge sort之時間複雜度。
*/

#include <iostream>

using namespace std;

class StoogeSort {
private:
    int* arr;
    int size;

public:
    StoogeSort(int arr[], int size) {
        this->arr = arr;
        this->size = size;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << arr[i];
        }
        cout << endl;
    }

    void stoogeSort(int left, int right) {

        if (left >= right) return;

        if (arr[left] > arr[right]) {
            swap(arr[left], arr[right]);
        }
        
        int gap = right - left + 1;

        if (gap > 2) {
            int split = gap / 3;

            stoogeSort(left, right - split);
            stoogeSort(left + split, right);
            stoogeSort(left, right - split);
        }
    }
};

int main()
{
    int arr[10] = { 60, 24, 15, 11, 2, 77, 1, 19, 89, 9 };
    int size = 10;

    StoogeSort obj(arr, size - 1);
    obj.printArray();

    obj.stoogeSort(0, size - 1);
    obj.printArray();

    system("pause");
    return 0;
}
