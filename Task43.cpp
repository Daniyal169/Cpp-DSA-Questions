// Min Max in BST

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

Node *minInTree(Node *root)
{
    Node *temp = root;

    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxInTree(Node *root)
{
    Node *temp = root;

    while (temp != NULL && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    Node *min = minInTree(root);
    cout << "Min is " << min->data;

    cout << endl;
    Node *max = maxInTree(root);
    cout << "Max is :" << max->data;

    return 0;
}
