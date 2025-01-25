// Linear Search using Recursion

#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size)
{
    if (size == 0)
    {
        return -1;
    }

    if (arr[0] == key)
    {
        return key;
    }
    else
    {
        int rest = linearSearch(arr + 1, key, size - 1);
        return rest;
    }
}

int main()
{
    int size = 5;
    int arr[6] = {1, 6, 9, 2, 0};
    int key;
    cout << "Enter key :";
    cin >> key;

    cout << linearSearch(arr, key, size) << endl;
}