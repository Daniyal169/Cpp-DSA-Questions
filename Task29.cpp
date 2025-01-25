// Selection SOrt using Recursion

#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }

    if (arr[0] > arr[1])
    {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }

    selectionSort(arr + 1, size - 1);
}

int main()
{
    int arr[5] = {3, 1, 6, 2, 9};
    int size = 5;

    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}