// when user enter 1 print last elem of queue when enter n print first

#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rare, maxSize;

public:
    Queue(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        front = 0;
        rare = 0;
    }

    void enqueue(int v)
    {
        arr[rare++] = v;
    }
    void dequeue()
    {
        front++;
    }

    void display()
    {
        for (int i = front; i < rare; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getReverse(int index)
    {
        int count = 1;
        // 10 20 30 40 50
        // 50 40 30 20 10
        for (int i = front; i < rare; i++)
        {
            arr[count] = arr[rare - 1 - i];
            count++;
        }
        return arr[index];
    }
};

int main()
{
    Queue queueObj(5);
    queueObj.enqueue(10);
    queueObj.enqueue(20);
    queueObj.enqueue(30);
    queueObj.enqueue(40);
    queueObj.enqueue(50);

    queueObj.display();

    cout << queueObj.getReverse(1) << endl;
}