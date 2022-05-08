#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int sumTree(Node *root, bool &flag)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    int left = sumTree(root->left, flag);
    int right = sumTree(root->right, flag);
    if (root->data == (left + right))
    {
        flag = true;
    }
    else
    {
        flag = false;
        return 0;
    }

    return root->data + left + right;
}

bool isSumTree(Node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return 1;

    bool flag = true;

    sumTree(root, flag);

    return flag;
}

int main()
{
    Node *root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 8;

    cout << isSumTree(root) << "\n";
    return 0;
}