// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

// https://discuss.geeksforgeeks.org/comment/eff4ddd3411f5edfce5aed0f1cec8cb6

#include <iostream>
#include <queue>

using namespace std;

// --------------------------------------------
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
// --------------------------------------------

int nodes(Node *root)
{
    if (!root)
        return 0;

    return 1 + nodes(root->left) + nodes(root->right);
}

bool isHeap(Node *root)
{
    int count = nodes(root);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            Node *t = q.front();
            q.pop();

            if (t->left && t->data >= t->left->data)
            {
                q.push(t->left);
                ++i;
            }
            else if (i != count)
                return false;

            if (t->right && t->data >= t->right->data)
            {
                q.push(t->right);
                ++i;
            }
            else if (i != count)
                return false;
        }
    }

    return true;
}

int main()
{
    // max Heap
    /*
            50
           /  \
          30  20
         /  \
        10   5
    */

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(5);

    cout << isHeap(root) << "\n";

    return 0;
}