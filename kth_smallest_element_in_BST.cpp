// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// https://discuss.geeksforgeeks.org/comment/d62db3aa9456bd609e632880b2fe6a93

#include <iostream>
using namespace std;

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

int k, ele;

void dfs(Node *root)
{
    if (!root)
        return;

    dfs(root->left);

    if (--k == 0)
    {
        ele = root->data;
        return;
    }

    dfs(root->right);
}

int KthSmallestElement(Node *root, int K)
{
    k = K;
    ele = -1;

    dfs(root);

    return ele;
}

int main()
{
    //   2
    //  / \
    // 1   3

    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    int k = 2;

    cout << KthSmallestElement(root, k) << "\n";

    return 0;
}