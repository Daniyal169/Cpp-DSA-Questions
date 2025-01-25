// Queue using Linked List|
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int v)
    {
        Node *newNode = new Node(v);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {

        Node *temp = front;
        front = front->next;

        delete temp;
    }

    void display()
    {

        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue after enqueuing : ";
    q.display();

    q.dequeue();
    cout << "Queue after dequeuing an element: ";
    q.display();

    q.enqueue(40);
    cout << "Queue after enqueuing 40: ";
    q.display();

    return 0;
}
