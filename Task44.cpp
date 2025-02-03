// Delete from BST

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

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node *findMin(Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        //---- if no child -> 0 child------
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //----- if left or right child  -> 1 child-------
        // left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //-------- if both left and right child  -> 2 child-------
        // if node has left or right then find either min from right or max from left
        Node *minNode = findMin(root->right);
        root->data = minNode->data;
        root->right = deleteBST(root->right, minNode->data);
    }

    if (val < root->data)
    {
        root->left = deleteBST(root->left, val);
        return root;
    }
    else if (val > root->data)
    {
        root->right = deleteBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    cout << "Inorder Traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    int delVal;
    cout << "Enter the value to delete: ";
    cin >> delVal;

    root = deleteBST(root, delVal);

    cout << "Inorder Traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
