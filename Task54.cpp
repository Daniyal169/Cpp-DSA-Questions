// Open Hashing function and deletion

#include <iostream>
#include <list>

using namespace std;

const int Size = 11;

list<int> hashArray[Size];

int hashFunction(int key)
{
    return (key % Size);
}

void insert(int key)
{
    int index = hashFunction(key);
    hashArray[index].push_back(key);
}

void deleteElem(int key)
{
    int index = hashFunction(key);

    bool found = false;

    for (auto i = hashArray[index].begin(); i != hashArray[index].end(); ++i)
    {
        if (*i == key)
        {
            hashArray[index].erase(i);
            found = true;
            cout << "Key " << key << " deleted successfully!" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Key " << key << " not found in the hash table." << endl;
    }
}

void display()
{
    for (int i = 0; i < Size; i++)
    {
        cout << i;
        for (auto elem : hashArray[i])
        {
            cout << "--->" << elem;
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 44, 35, 31, 40, 10, 8, 6, 50, 69, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);
    }

    display();

    deleteElem(31);
    display();
}