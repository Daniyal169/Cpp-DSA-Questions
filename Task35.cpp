// Check for balanced Tree

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

bool isBalanced(Node *root)
{
    if (root = NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    int difference = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;

    if (left && right && difference)
        return true;

    return false;
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 7);
    insert(root, 20);
    insert(root, 15);
    insert(root, 30);
    insert(root, 35);
    insert(root, 12);
    insert(root, 40);

    cout << "Is Tree Balanced : " << isBalanced(root);

    return 0;
}
