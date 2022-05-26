// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/0/#

// https://discuss.geeksforgeeks.org/comment/8171a901436af5a563f9b3a4bb21d2dd

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

int check(Node *root, bool &flag)
{
    if (root == NULL)
        return 0;

    int left = check(root->left, flag);
    int right = check(root->right, flag);

    if (abs(left - right) > 1)
    {
        flag = false;
        return -1;
    }

    return 1 + max(left, right);
}

bool isBalanced(Node *root)
{
    bool flag = true;
    check(root, flag);

    return flag;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    cout << boolalpha << isBalanced(root) << "\n";
    return 0;
}