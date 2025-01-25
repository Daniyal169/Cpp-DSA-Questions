// Height of Binnary Tree

#include <iostream>
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

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 0);
    insert(root, 1);
    insert(root, 7);
    insert(root, 9);
    insert(root, 2);
    insert(root, 3);
    insert(root, 14);
    insert(root, 18);

    cout << "Height of Tree is : " << heightOfTree(root);

    return 0;
}
