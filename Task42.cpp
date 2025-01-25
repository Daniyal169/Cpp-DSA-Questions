// Search in BST

#include <iostream>
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

bool searchTree(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return searchTree(root->left, key);
    }
    else
    {
        return searchTree(root->right, key);
    }
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    if (searchTree(root, key))
    {
        cout << "Key " << key << " is found in the tree." << endl;
    }
    else
    {
        cout << "Key " << key << " is not found in the tree." << endl;
    }

    return 0;
}
