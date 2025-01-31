// First and last occurrence of element in an sorted array also find total occurrence
// using binnary search

#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int size, int key)
{

    int start = 0, end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int lastOccurrence(int arr[], int size, int key)
{

    int start = 0, end = size - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    const int size = 10;
    int arr[] = {0, 1, 1, 2, 2, 3, 3, 3, 3, 3};
    int key;

    cout << "ENter key you want to search :";
    cin >> key;

    int first = firstOccurrence(arr, size, key);
    int last = lastOccurrence(arr, size, key);

    cout << "The first occurrence is :" << first << endl;
    cout << "The last occurrence is :" << last << endl;

    cout << "Total occurrence is :" << (last - first) + 1;
}