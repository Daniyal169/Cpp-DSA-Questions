// Frequency counter for strings
#include <iostream>
#include <unordered_map>

using namespace std;

void frequencyCounter(string str)
{
    unordered_map<string, int> mapObj;
    string word = "";
    int maxFreq = 0;
    string maxFreqWord;

    for (char ch : str)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        {
            if (!word.empty())
            {
                mapObj[word]++;
                word = "";
            }
        }
    }

    if (!word.empty())
    {
        mapObj[word]++;
    }

    for (auto pair : mapObj)
    {
        if (pair.second > maxFreq)
        {
            maxFreq = pair.second;
            maxFreqWord = pair.first;
        }
    }

    cout << "Max freq word is :" << maxFreqWord << endl;
    cout << "Max freq is :" << maxFreq << endl;
}

int main()
{
    string str = "My name is Daniyal I am Daniyal";

    frequencyCounter(str);
}