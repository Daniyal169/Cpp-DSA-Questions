// Heap Sort

#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap(int n)
    {
        size = n;
    }

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= size && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right <= size && arr[right] > arr[largest])
        {
            largest = right;
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

    void heapSort()
    {
        buildHeap();

        for (int i = size; i >= 2; i--)
        {
            swap(arr[1], arr[i]);

            size--;

            heapify(1);
        }
    }

    // Display the array
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
    int arr[] = {-1, 70, 60, 55, 50, 45, 75};
    int n = 6;

    Heap heapObj(n);

    // Copy values into the heap object
    for (int i = 1; i <= n; i++)
    {
        heapObj.arr[i] = arr[i];
    }

    cout << "Original Array: ";
    heapObj.display();

    heapObj.heapSort();

    cout << "Sorted Array: ";
    heapObj.display();

    return 0;
}
