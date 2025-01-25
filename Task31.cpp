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

void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->rollNo << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << root->rollNo << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->rollNo << " ";
    }
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

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
