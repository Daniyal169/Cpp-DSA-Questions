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
    while (curr != NULL)
    {
        Node *temp = curr;
        while (temp->next != NULL)
        {
            if (temp->next->value == curr->value)
            {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
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
    insertAtHead(head, 1);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 6);
    cout << "Before removing duplicates :";
    display(head);
    cout << endl;
    removeDuplicates(head);
    cout << "After removing duplicates :";
    display(head);
}