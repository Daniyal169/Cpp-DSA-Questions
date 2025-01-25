// Check palindrome

#include <iostream>
using namespace std;

class Node
{
public:
    char value;
    Node *next;
    Node(char v)
    {
        value = v;
        next = NULL;
    }
};

void insertVal(Node *&tail, char v)
{
    Node *temp = new Node(v);
    tail->next = temp;
    tail = temp;
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

bool checkPalindrome(Node *&head)
{
    int length = getLength(head);
    int mid = length / 2;
    Node *temp = head;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    Node *prev = NULL, *current = temp, *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    Node *firstHalf = head;
    Node *secondHalf = prev;

    while (secondHalf != NULL)
    {
        if (firstHalf->value != secondHalf->value)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *newNode = new Node('D');
    Node *head = newNode;
    Node *tail = newNode;

    insertVal(tail, 'A');
    insertVal(tail, 'N');
    insertVal(tail, 'I');
    insertVal(tail, 'Y');
    insertVal(tail, 'A');
    insertVal(tail, 'L');
    display(head);

    if (checkPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }
}