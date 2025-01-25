// Remove duplicates from sorted linkedlist

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

void insertAtHead(Node *&head, int v)
{
    Node *temp = new Node(v);
    temp->next = head;
    head = temp;
}

void removeDuplicates(Node *&head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->value == curr->next->value)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    cout << endl;
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
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 20);
    insertAtHead(head, 20);
    cout << "Before removing duplicates :";
    display(head);
    cout << endl;
    removeDuplicates(head);
    cout << "After removing duplicates :";
    display(head);
}