// Output restricted Queue -->> means pop from only one side and push from both using singly queue

#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rare, size, count;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = 0;
        rare = 0;
        count = 0;
    }

    void enqueueFront(int v)
    {
        if (count == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = v;
            count++;
        }
    }

    void enqueueBack(int v)
    {
        if (count == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rare] = v;
            rare = (rare + 1) % size;
            count++;
        }
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front = (front + 1) % size;
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
                index = (index + 1) % size;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queObj(5);

    queObj.enqueueBack(10);
    queObj.enqueueBack(20);
    queObj.enqueueBack(5);
    queObj.enqueueBack(30);
    queObj.enqueueBack(2);

    cout << "Queue after enqueue operations: ";
    queObj.display();

    queObj.dequeue();
    queObj.dequeue();
    cout << "Queue after dequeuing from front: ";
    queObj.display();

    queObj.enqueueFront(40);
    queObj.enqueueFront(60);
    cout << "Queue after enqueue at front: ";
    queObj.display();

    return 0;
}
