// https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1

// https://discuss.geeksforgeeks.org/comment/a398527152cbaf93fed9b783354bb63f

#include <iostream>
using namespace std;

// ---------------------------------------------
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
// ---------------------------------------------

Node *dfs(Node *root, int &target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
        return root;

    if (root->data > target)
        return dfs(root->left, target);

    return dfs(root->right, target);
}

long long vertical(Node *root, int hd)
{
    if (root == NULL)
        return 0ll;

    if (hd == 0)
        return root->data + vertical(root->left, hd - 1) + vertical(root->right, hd + 1);

    return vertical(root->left, hd - 1) + vertical(root->right, hd + 1);
}

long long int verticallyDownBST(Node *root, int target)
{
    Node *node = dfs(root, target);
    if (node == NULL)
        return -1;

    return vertical(node, 0) - node->data;
}

int main()
{
    /*
               25
              /  \
            20    35
           / \    / \
          15 22  30 45
                   \
                   32
    */

    Node *root = new Node(25);
    root->left = new Node(20);
    root->right = new Node(35);
    root->left->left = new Node(15);
    root->left->right = new Node(22);
    root->right->left = new Node(30);
    root->right->right = new Node(45);
    root->right->left->right = new Node(32);

    int target = 35;
    cout << verticallyDownBST(root, target) << "\n";

    return 0;
}