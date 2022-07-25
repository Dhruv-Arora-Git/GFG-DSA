// https://practice.geeksforgeeks.org/problems/symmetric-tree/1?page=1&category%5B%5D=Tree&curated%5B%5D=1&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/e0e0c690ebc6c67886e7b28993838d84

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

bool inorder(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) && inorder(root1->left, root2->right) && inorder(root1->right, root2->left);
}

bool isSymmetric(struct Node *root)
{
    if (root == NULL)
        return true;

    return inorder(root->left, root->right);
}

int main()
{
    //        5
    //       / \
    //      1   1
    //     /     \
    //    2       2

    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->right->right = new Node(2);

    cout << boolalpha << isSymmetric(root) << "\n";

    return 0;
}