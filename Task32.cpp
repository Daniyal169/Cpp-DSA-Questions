// Traversal without ecurssion
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int rollNo;
    Node *left;
    Node *right;

    Node(int value)
    {
        rollNo = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->rollNo)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorderTraversalWithoutRecursion(Node *root)
{
    stack<Node *> s;
    Node *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->rollNo << " ";

        current = current->right;
    }
}

void preorderTraversalWithoutRecursion(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *current = s.top();
        s.pop();

        cout << current->rollNo << " ";

        if (current->right)
        {
            s.push(current->right);
        }
        if (current->left)
        {
            s.push(current->left);
        }
    }
}

void postorderTraversalWithoutRecursion(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left)
        {
            s1.push(current->left);
        }
        if (current->right)
        {
            s1.push(current->right);
        }
    }

    while (!s2.empty())
    {
        cout << s2.top()->rollNo << " ";
        s2.pop();
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

    cout << "Inorder Traversal (Without Recursion): ";
    inorderTraversalWithoutRecursion(root);
    cout << endl;

    cout << "Preorder Traversal (Without Recursion): ";
    preorderTraversalWithoutRecursion(root);
    cout << endl;

    cout << "Postorder Traversal (Without Recursion): ";
    postorderTraversalWithoutRecursion(root);
    cout << endl;

    return 0;
}
