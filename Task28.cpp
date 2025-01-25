// Palindrome using Recursion

#include <iostream>
using namespace std;

bool palindrome(string &str, int i, int size)
{
    if (i >= size / 2)
    {
        return true;
    }

    if (str[i] != str[size - i])
    {
        return false;
    }

    return palindrome(str, i + 1, size);
}

int main()
{
    string name;
    cout << "Enter name :";
    cin >> name;

    bool check = palindrome(name, 0, name.length() - 1);

    if (check)
    {
        cout << "Name is palindrome";
    }
    else
    {
        cout << "Name is not palindrome";
    }
}