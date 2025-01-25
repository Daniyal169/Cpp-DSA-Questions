// check is array sorted using recurrsion

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remaining = isSorted(arr + 1, size - 1);
        return remaining;
    }
}

int main()
{
    int size = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    cout << isSorted(arr, size);
}