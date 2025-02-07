// Reverse String using Recursion

#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end)
{

    if (start > end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;

    reverseString(str, start, end);
}

int main()
{
    string team;
    cout << "Enter :";
    cin >> team;

    reverseString(team, 0, team.length() - 1);

    cout << team;
}
