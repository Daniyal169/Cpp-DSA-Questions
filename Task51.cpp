// Maximun frequency number

#include <iostream>
#include <unordered_map>

using namespace std;

void frequencyCounter(int arr[], int size)
{
    unordered_map<int, int> freqMap;

    for (int i = 0; i < size; i++)
    {
        freqMap[arr[i]]++;
    }

    int maxFreq = 0;
    int numberWithMaxFreq = -1;

    for (auto pair : freqMap)
    {
        if (pair.second > maxFreq)
        {
            maxFreq = pair.second;
            numberWithMaxFreq = pair.first;
        }
    }

    cout << "Number with maximum frequency: " << numberWithMaxFreq << endl;
    cout << "Frequency: " << maxFreq << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 3, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    frequencyCounter(arr, size);

    return 0;
}
