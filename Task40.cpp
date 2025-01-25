// Build Tree from inorder and pre order traversal

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

int findIndex(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int &preorderIndex, int inorderStart, int inorderEnd)
{
    if (inorderStart > inorderEnd)
    {
        return nullptr;
    }

    int rootValue = preorder[preorderIndex];
    preorderIndex++;

    Node *root = new Node(rootValue);

    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, rootValue);

    root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1);
    root->right = buildTree(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd);

    return root;
}

void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    int preorder[] = {0, 1, 3, 4, 2, 5};
    int inorder[] = {3, 1, 4, 0, 5, 2};

    int preorderIndex = 0;
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node *root = buildTree(preorder, inorder, preorderIndex, 0, n - 1);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
