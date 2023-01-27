// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// https://discuss.geeksforgeeks.org/comment/695277b6ae578d595130babe07821770

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

// ---------------------------------
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// ---------------------------------

vector<int> bottomView(Node *root)
{
    map<int, int> distance;

    queue<pair<Node *, int>> q; // node, hd

    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<Node *, int> pr = q.front();
            q.pop();
            Node *node = pr.first;
            int val = pr.second;

            distance[val] = node->data;

            if (node->left)
                q.push({node->left, val - 1});

            if (node->right)
                q.push({node->right, val + 1});
        }
    }

    vector<int> v;

    for (auto &it : distance)
        v.push_back(it.second);

    return v;
}

int main()
{
    /*
                      20
                     /  \
                    8   22
                   / \  / \
                  5  3 4   25
                     /  \
                   10    14
    */

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    vector<int> v = bottomView(root);

    for (int &i : v)
        cout << i << " ";

    cout << "\n";

    return 0;
}