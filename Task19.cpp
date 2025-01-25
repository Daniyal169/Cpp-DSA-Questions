// Delete Mid of linked List

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
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

int delMid(Node *head)
{
    if (head->next == NULL)
    {
        return head->value;
    }
    if (head->next->next == NULL)
    {
        return head->next->value;
    }

    Node *fast = head->next->next;
    Node *slow = head;
    Node *prevNode = NULL;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        prevNode = slow;
        slow = slow->next;
    }
    prevNode->next = slow->next;
    delete slow;
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
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtHead(head, 50);
    insertAtHead(head, 80);
    display(head);
    delMid(head);
    display(head);
}