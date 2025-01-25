// Stack using Template
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
protected:
    T *arr;
    int maxSize, currSize;

public:
    Stack(int size)
    {
        maxSize = size;
        arr = new T[maxSize];
        currSize = 0;
    }

    virtual void push(T val) = 0;
    virtual void onTop() = 0;
    virtual void pop() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
    virtual void display() = 0;
};

template <typename T>
class StackChild : public Stack<T>
{
public:
    StackChild(int size) : Stack<T>(size) {}

    void push(T val)
    {
        this->arr[this->currSize++] = val;
    }

    void onTop()
    {
        cout << arr[currSize - 1] << endl;
    }

    void pop()
    {
        this->currSize--;
    }

    void isEmpty()
    {
        if (this->currSize == 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "STack is not empty";
        }
    }

    void isFull()
    {
        if (this->currSize == this->maxSize)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "STack is not full";
        }
    }

    void display()
    {
        for (int i = 0; i < this->currSize; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    StackChild<int> stackObj(5);

    stackObj.push(10);
    stackObj.push(20);
    stackObj.push(30);
    stackObj.push(40);
    stackObj.push(50);

    stackObj.display();

    stackObj.onTop();

    stackObj.pop();

    stackObj.display();

    stackObj.isEmpty();
    stackObj.isFull();
}