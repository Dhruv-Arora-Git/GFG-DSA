// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/0/?page=1&category[]=Tree&sortBy=submissions#

// https://discuss.geeksforgeeks.org/comment/5fa2db09fd2ab2df22d5ec692641c474

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    cout << height(root) << "\n";

    return 0;
}