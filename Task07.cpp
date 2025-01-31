// Find middle TC=N/2
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

int findMid(Node *&head)
{

    if (head == NULL)
    {
        return -1;
    }

    if (head->next == NULL)
    {
        return head->value;
    }

    if (head->next->next == NULL)
    {
        return head->next->value;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }
    return slow->value;
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
    insertHead(head, 80);
    display(head);
    cout << findMid(head) << " " << endl;
}