// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&category%5B%5D=Tree&curated%5B%5D=1&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/f834feade880a95e398c25530a75c942

#include <iostream>
using namespace std;

// --------------------------
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// --------------------------

int countLeaves(Node *root)
{
    if (root == NULL)
        return 0;

    return (root->left == NULL && root->right == NULL) ? 1 : 0 + countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    //        4
    //       / \
    //      8   10
    //     /    / \
    //    7    5   1
    //   /
    //  2

    Node *root = new Node(4);
    root->left = new Node(8);
    root->right = new Node(10);
    root->left->left = new Node(7);
    root->right->right = new Node(1);
    root->right->left = new Node(5);
    root->left->left->left = new Node(3);

    cout << countLeaves(root) << "\n";

    return 0;
}