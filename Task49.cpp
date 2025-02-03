// Heapify alogrithm
#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap(int arr[], int n)
    {
        size = n;
        for (int i = 1; i <= n; i++)
        {
            this->arr[i] = arr[i - 1];
        }
    }

    void heapify(int i)
    {
        int leftIndex = 2 * i;
        int rightIndex = (2 * i) + 1;

        int largest = i;

        if (leftIndex <= size && arr[leftIndex] > arr[largest])
        {
            largest = leftIndex;
        }

        if (rightIndex <= size && arr[rightIndex] > arr[largest])
        {
            largest = rightIndex;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            heapify(largest);
        }
    }

    void buildHeap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            heapify(i);
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int inputArr[] = {50, 55, 60, 45, 70, 75};
    int n = sizeof(inputArr) / sizeof(inputArr[0]);

    Heap heapObj(inputArr, n);

    cout << "Before heapify: ";
    heapObj.display();

    heapObj.buildHeap();

    cout << "After heapify: ";
    heapObj.display();

    return 0;
}
