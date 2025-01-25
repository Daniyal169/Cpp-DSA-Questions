// Implementing stack using linkedlist

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

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int v)
    {
        Node *newNode = new Node(v);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void isEmpty()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }

    void display()
    {
        Node *temp = top;
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
    Stack stackObj;

    stackObj.push(10);
    stackObj.push(20);
    stackObj.push(30);
    stackObj.push(40);
    stackObj.push(50);

    stackObj.display();

    stackObj.pop();

    stackObj.display();

    stackObj.isEmpty();
}