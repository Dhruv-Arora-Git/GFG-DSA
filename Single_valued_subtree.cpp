// https://practice.geeksforgeeks.org/problems/single-valued-subtree/1

// https://discuss.geeksforgeeks.org/comment/b978eafb927dc1f1f385f766b1c30cb2

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

bool dfs(Node *root, Node *prev, int &count)
{
    if (!root)
        return true;

    bool leftMatch = dfs(root->left, root, count);
    bool rightMatch = dfs(root->right, root, count);

    if (leftMatch && rightMatch)
        ++count;

    return leftMatch && rightMatch &&
                   prev
               ? prev->data == root->data
               : false;
}

int singlevalued(Node *root)
{
    int count = 0;
    dfs(root, NULL, count);

    return count;
}

int main()
{
    //       5
    //      / \
    //     1   5
    //    / \   \
    //   5   5   5

    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(5);
    root->left->left = new Node(5);
    root->left->right = new Node(5);
    root->right->right = new Node(5);

    cout << singlevalued(root) << "\n";

    return 0;
}