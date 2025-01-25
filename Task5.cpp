// Reverse the LinkedList using 2nd approach

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

void insertVal(Node *&head, int v)
{
    Node *temp = new Node(v);
    temp->next = head;
    head = temp;
}

void reverse(Node *&head, Node *&curr, Node *&prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    curr->next = prev;
    reverse(head, forward, curr);
}

void reverseNode(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
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
    Node *newNode = new Node(10);
    Node *head = newNode;
    insertVal(head, 20);
    insertVal(head, 30);
    insertVal(head, 40);
    insertVal(head, 50);

    display(head);
    cout << endl;
    reverseNode(head);

    display(head);
}