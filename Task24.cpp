// Sum array using recursion

#include <iostream>
using namespace std;

int sumArr(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int rest = sumArr(arr + 1, size - 1);
    return arr[0] + rest;
}

int main()
{
    int size = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    cout << sumArr(arr, size);
}