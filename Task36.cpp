// Check if two tree are identical

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }

    if (val < root->value)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 != NULL && root2 == NULL || root1 == NULL && root2 != NULL)
        return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool value = root1->value == root2->value;

    if (left && right && value)
        return true;
    return false;
}

int main()
{
    Node *root1 = nullptr;
    Node *root2 = nullptr;

    root1 = insert(root1, 10);
    insert(root1, 5);
    insert(root1, 15);
    insert(root1, 3);
    insert(root1, 7);

    root2 = insert(root2, 10);
    insert(root2, 5);
    insert(root2, 15);
    insert(root2, 3);
    insert(root2, 7);

    cout << "Is Tree Identical : " << isIdentical(root1, root2);

    return 0;
}
