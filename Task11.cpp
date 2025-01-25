// 2 Stack in an array
#include <iostream>

using namespace std;

class Stack
{
    int *arr;
    int maxSize, currOne, currTwo;

public:
    Stack(int s)
    {
        maxSize = s;
        arr = new int[maxSize];
        currOne = 0;
        currTwo = maxSize - 1;
    }

    void pushOne(int v)
    {
        if (currOne <= currTwo)
        {
            arr[currOne++] = v;
        }
        else
        {
            cout << "Stack is full";
        }
    }

    void pushTwo(int v)
    {
        if (currTwo >= currOne)
        {
            arr[currTwo--] = v;
        }
        else
        {
            cout << "Stack is full";
        }
        cout << endl;
    }

    void popOne()
    {
        currOne--;
        arr[currOne] = 0;
    }
    void popTwo()
    {
        currTwo++;
        arr[currTwo] = 0;
    }

    void display()
    {
        for (int i = 0; i < maxSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stackObj(4);

    stackObj.pushOne(10);
    stackObj.pushTwo(40);
    stackObj.pushOne(30);
    stackObj.pushTwo(50);

    stackObj.display();

    stackObj.popOne();
    stackObj.popTwo();
    stackObj.display();
}