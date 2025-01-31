// First and last occurrence of element in an sorted array

#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[] = {0, 1, 1, 2, 2, 3, 3, 3, 3, 3};
    int key, count[10], countInd = 0;
    cout << "Enter elem you want to check occurrence :";
    cin >> key;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            count[countInd++] = i;
        }
    }

    if (countInd == 0)
    {
        cout << "Element not found in the array." << endl;
    }
    else
    {
        cout << "First occurrence: " << count[0] << endl;
        cout << "Last occurrence: " << count[countInd - 1] << endl;
    }
}