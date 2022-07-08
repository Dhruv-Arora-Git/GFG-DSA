// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/?page=1&category[]=Tree&curated[]=1&sortBy=submissions#

// https://discuss.geeksforgeeks.org/comment/1e34f97f1dcf084f6dafdecdb52ab166

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

int i = 0, k;
void dfs(Node *root, int &a)
{
    if (root == NULL)
        return;

    dfs(root->right, a);
    ++i;
    if (i == k)
        a = root->data;

    dfs(root->left, a);
}
int kthLargest(Node *root, int K)
{
    int a = -1;
    k = K;
    dfs(root, a);

    return a;
}

int main()
{

    // create a BST
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // print the kth largest element in the BST
    cout << kthLargest(root, 3) << "\n";

    return 0;
}