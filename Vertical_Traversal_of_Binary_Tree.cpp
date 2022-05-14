// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#

// https://discuss.geeksforgeeks.org/comment/cbf22c8841e5b1a89fa8c965c5df41e8

#include <iostream>
#include <queue>
#include <vector>
#include <map>

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

map<int, vector<int>> mp;

void traverse(Node *root)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            Node *t = q.front().first;
            int hd = q.front().second;
            mp[hd].push_back(t->data);
            q.pop();

            if (t->left)
                q.push({t->left, hd - 1});

            if (t->right)
                q.push({t->right, hd + 1});
        }
    }
}

vector<int> verticalOrder(Node *root)
{
    vector<int> v;
    mp.clear();
    if (root == NULL)
        return {};

    traverse(root);

    for (auto it : mp)
    {
        v.insert(v.end(), it.second.begin(), it.second.end());
    }

    return v;
}
int main()
{
    //            1
    //          /   \
    //        2       3
    //      /   \   /   \
    //    4      5 6      7
    //               \      \
    //                8      9

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> v = verticalOrder(root);

    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}