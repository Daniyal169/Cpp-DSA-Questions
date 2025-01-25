// Build Tree from inorder and post order traversal

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

Node *buildTree(int inorder[], int postorder[], int &postorderIndex, int inorderStart, int inorderEnd)
{
    if (inorderStart > inorderEnd)
    {
        return nullptr;
    }

    int rootValue = postorder[postorderIndex];
    postorderIndex--;

    Node *root = new Node(rootValue);

    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, rootValue);

    root->right = buildTree(inorder, postorder, postorderIndex, inorderIndex + 1, inorderEnd);
    root->left = buildTree(inorder, postorder, postorderIndex, inorderStart, inorderIndex - 1);

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
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int postorder[] = {3, 4, 1, 5, 2, 0};

    int postorderIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node *root = buildTree(inorder, postorder, postorderIndex, 0, n - 1);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
