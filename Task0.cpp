// Hashing Implementation using Separate Chaining in C++

#include <iostream>
#include <list>
using namespace std;

const int n = 7;

list<int> hashtable[n];

int hashFunction(int x)
{
    return (x % n);
}

void insert_key(int key)
{
    int index = hashFunction(key);
    hashtable[index].push_back(key);
}

void delete_key(int key)
{
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = hashtable[index].begin(); i != hashtable[index].end(); i++)
    {
        if (*i == key)
            break;
        else
            cout << "Key not found" << endl;
    }

    if (i != hashtable[index].end())
    {
        hashtable[index].erase(i);

        cout << "Hash table after deletion:" << endl;
    }
}

void displayHash()
{
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : hashtable[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int hash_array[] = {11, 12, 21, 14, 15};
    int n = sizeof(hash_array) / sizeof(hash_array[0]);

    for (int i = 0; i < n; i++)
        insert_key(hash_array[i]);

    cout << "Hash table created:" << endl;
    displayHash();

        delete_key(21);

    displayHash();

    return 0;
}
