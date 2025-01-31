// Peak index in mounting array

#include <iostream>
using namespace std;

int findPeak(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 4, 5, 50, 1};
    cout << findPeak(arr, 6) << endl;
}