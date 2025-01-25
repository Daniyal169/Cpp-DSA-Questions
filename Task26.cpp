#include <iostream>
using namespace std;

bool binnarySearch(int arr[], int key, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return 1;
    }
    else if (arr[mid] > key)
    {
        return binnarySearch(arr, key, start, mid - 1);
    }
    else
    {
        return binnarySearch(arr, key, mid + 1, end);
    }
}

int main()
{
    int size = 5;
    int arr[5] = {2, 4, 6, 8, 10};

    int key;
    cout << "Enter key";
    cin >> key;
    int start = 0, end = size - 1;
    cout << binnarySearch(arr, key, start, end);
}