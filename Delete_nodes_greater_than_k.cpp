// https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1

// https://discuss.geeksforgeeks.org/comment/033bc59f978ca230ced6f7aa9509a304

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;

    Node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

Node *deleteNode(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    Node *left = deleteNode(root->left, k);
    root->left = left;

    // no need to check the right subtree,
    // as in BST, all values to right of root will always be larger than root (as well as k)
    if (root->data >= k)
        return left;

    Node *right = deleteNode(root->right, k);
    root->right = right;

    return root;
}

void print(Node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    Node *root = new Node(100);
    root->left = new Node(80);
    root->right = new Node(120);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(50);

    root = deleteNode(root, 80);
    print(root);
    cout << "\n";
    return 0;
}