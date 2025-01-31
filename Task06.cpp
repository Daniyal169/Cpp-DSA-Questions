// Find middle TC=N

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

void insertHead(Node *&head, int v)
{
    Node *temp = new Node(v);
    temp->next = head;
    head = temp;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void findMid(Node *&head)
{
    int len = getLength(head);
    int midIndex = len / 2;
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {

        if (count == midIndex)
        {
            cout << "Mid element :" << temp->value << endl;
            return;
        }
        count++;
        temp = temp->next;
    }
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *newNode = new Node(5);
    Node *head = newNode;
    insertHead(head, 20);
    insertHead(head, 10);
    insertHead(head, 50);
    findMid(head);
    display(head);
}