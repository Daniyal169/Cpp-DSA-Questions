// Insertion and deletion in HEAP

#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // insertion in heap
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;

                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // delete
    void deleteElem()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            int leftIndex = i * 2;
            int rightIndex = (i * 2) + 1;

            int largest = i; // Assume the largest element is the current node

            // Check if the left child exists and is larger than the current node
            if (leftIndex <= size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }

            // Check if the right child exists and is larger than the current largest
            if (rightIndex <= size && arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }

            // If the largest value is the current node, stop the process
            if (largest == i)
            {
                break;
            }

            // Swap the current node with the largest child
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Move to the next level in the heap
            i = largest;
        }
    }

    // print
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
    Heap heapObj;
    heapObj.insert(50);
    heapObj.insert(55);
    heapObj.insert(60);
    heapObj.insert(45);
    heapObj.insert(70);
    heapObj.insert(75);

    heapObj.display();

    heapObj.deleteElem();
    heapObj.display();
}