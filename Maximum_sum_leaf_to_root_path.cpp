// https://practice.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1

// https://discuss.geeksforgeeks.org/comment/7bb36ac6d9fd7640fb75345dcae5d01d

#include <iostream>
#include <climits>

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
int mxSum = INT_MIN;

void dfs(Node *root, int sum)
{
    if (root == NULL)
    {
        mxSum = max(mxSum, sum);
        return;
    }

    sum += root->data;

    dfs(root->left, sum);
    dfs(root->right, sum);
}

int maxPathSum(Node *root)
{
    dfs(root, 0);

    return mxSum;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    cout << maxPathSum(root) << "\n";

    return 0;
}