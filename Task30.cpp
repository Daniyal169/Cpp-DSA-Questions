// Bubble Sort using Recursion

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, size - 1);
}

int main()
{
    int arr[5] = {3, 1, 6, 2, 9};
    int size = 5;

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}