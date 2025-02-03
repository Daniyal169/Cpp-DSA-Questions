// is BST Dead

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

bool isDeadEnd(Node *root, int min, int max)
{
    if (root == NULL)
        return false;

    if (min == max)
        return true;

    bool left = isDeadEnd(root->left, min, root->data - 1);
    bool right = isDeadEnd(root->right, root->data + 1, max);

    return left || right;
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    if (isDeadEnd(root, 1, INT_MAX))
    {
        cout << "The BST contains a dead end." << endl;
    }
    else
    {
        cout << "The BST does not contain a dead end." << endl;
    }

    return 0;
}
