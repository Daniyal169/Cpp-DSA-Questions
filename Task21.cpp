#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n, arr);
    cout << arr[digit - 1] << " ";
}

int main()
{
    string arr[9] = {"one",
                     "two",
                     "three",
                     "four",
                     "five",
                     "six",
                     "seven",
                     "eight",
                     "nine"};

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n == 0)
    {
        cout << "zero";
    }
    else
    {
        sayDigit(n, arr);
    }

    return 0;
}
