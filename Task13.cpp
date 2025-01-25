// Input restricted Queue  -->> means push from only one side and pop from both

#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rare, count, maxSize;

public:
    Queue(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        front = 0;
        rare = 0;
        count = 0;
    }

    void enqueue(int v)
    {
        if (count == maxSize)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rare] = v;
            rare = (rare + 1) % maxSize;
            count++;
        }
    }

    void denqueueFront()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front = (front + 1) % maxSize;
            count--;
        }
    }

    void denqueueRare()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            rare = (rare - 1 + maxSize) % maxSize;
            count--;
        }
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int index = front;
            for (int i = 0; i < count; i++)
            {
                cout << arr[index] << " ";
                index = (index + 1) % maxSize;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queObj(5);
    queObj.enqueue(10);
    queObj.enqueue(20);
    queObj.enqueue(30);
    queObj.enqueue(40);
    queObj.enqueue(50);

    queObj.display();

    queObj.denqueueFront();
    queObj.display();

    queObj.denqueueRare();
    queObj.display();

    return 0;
}