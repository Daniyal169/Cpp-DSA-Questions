// IS BST VALID OR NOT

#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        return new Node(d);
    }

    if (d < root->data)
    {
        root->left = insertIntoBST(root->left, d);
    }
    else
    {
        root->right = insertIntoBST(root->right, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int num;
    cout << "Enter numbers to insert into the BST (-1 to stop): ";
    cin >> num;

    while (num != -1)
    {
        root = insertIntoBST(root, num);
        cin >> num;
    }
}

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;

    bool left = isBST(root->left, min, root->data - 1);
    bool right = isBST(root->right, root->data + 1, max);

    return left && right;
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    if (isBST(root, INT_MIN, INT_MAX))
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
