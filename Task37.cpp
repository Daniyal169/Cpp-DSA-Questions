// ZIgZag Traversal

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Queue
{
public:
    Node **arr;
    int front;
    int rear;
    int size;
    int count;

public:
    Queue(int s)
    {
        size = s;
        arr = new Node *[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    void enqueue(Node *value)
    {
        if (count == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = value;
            rear = (rear + 1) % size;
            count++;
        }
    }

    Node *dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        else
        {
            Node *temp = arr[front];
            front = (front + 1) % size;
            count--;
            return temp;
        }
    }

    bool isEmpty()
    {
        return count == 0;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void zigzagLevelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    Queue q(100);
    q.enqueue(root);

    bool leftToRight = true;

    while (!q.isEmpty())
    {
        int levelSize = q.count;
        int levelNodes[levelSize];

        for (int i = 0; i < levelSize; i++)
        {
            Node *current = q.dequeue();
            levelNodes[i] = current->data;

            if (current->left)
            {
                q.enqueue(current->left);
            }
            if (current->right)
            {
                q.enqueue(current->right);
            }
        }

        if (leftToRight)
        {
            for (int i = 0; i < levelSize; i++)
            {
                cout << levelNodes[i] << " ";
            }
        }
        else
        {
            for (int i = levelSize - 1; i >= 0; i--)
            {
                cout << levelNodes[i] << " ";
            }
        }

        leftToRight = !leftToRight;
    }
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Zigzag Level-order Traversal: ";
    zigzagLevelOrderTraversal(root);

    return 0;
}
