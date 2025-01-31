// reverse an array and find position of largest and second largest number before and after

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Original Array :";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int size)
{
    int count = 0;
    while (count < (size / 2))
    {
        int temp = arr[size - 1 - count];
        arr[size - 1 - count] = arr[count];
        arr[count] = temp;
        count++;
    }
}

void printReverse(int arr[], int size)
{
    cout << "Array after reverse :";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxBefore(int arr[], int size)
{
    int max = 0, maxTwo = 0;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        if (arr[i] > max)
        {
            max = i;
        }

        if (arr[i] > maxTwo && arr[i] != max)
        {
            maxTwo = i;
        }
    }
    cout << endl;
    cout << "Before Max is at index " << max << endl;
    cout << "Before  2nd Max is at index " << maxTwo << endl;
    cout << endl;
}
void maxAfter(int arr[], int size)
{
    int max = 0, maxTwo = 0;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        if (arr[i] > max)
        {
            max = i;
        }

        if (arr[i] > maxTwo && arr[i] != max)
        {
            maxTwo = i;
        }
    }
    cout << endl;
    cout << "After Max is at index " << max << endl;
    cout << "After  2nd Max is at index " << maxTwo << endl;
    cout << endl;
}

int main()
{
    const int size = 10;
    int arr[10] = {1, 2, 4, 5, 9, 6, 3, 0, 10, 7};

    printArray(arr, size);

    maxBefore(arr, size);
    maxAfter(arr, size);

    reverseArray(arr, size);
    maxBefore(arr, size);
    maxAfter(arr, size);

    printReverse(arr, size);
}