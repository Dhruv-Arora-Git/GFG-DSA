// https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1

// https://discuss.geeksforgeeks.org/comment/6d6efec8519dbc82eda99e2e7a0fea0e

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

int subtreeSum(Node *root, int &maxSum)
{
    if (!root)
        return 0;

    int leftSum = subtreeSum(root->left, maxSum);
    int rightSum = subtreeSum(root->right, maxSum);
    int sum = root->data + leftSum + rightSum;

    maxSum = max(maxSum, sum);

    return sum;
}

int findLargestSubtreeSum(Node *root)
{
    int maxSum = -1e9;
    subtreeSum(root, maxSum);
    return maxSum;
}

int main()
{
    //      1
    //    /   \
    //  -2     3
    //  / \   /  \
    // 4   5 -6   2

    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root) << "\n";

    return 0;
}