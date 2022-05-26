// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/0/#

// https://discuss.geeksforgeeks.org/comment/ce4a5da2ec9e42016e5d07611152bc49

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

map<int, int> hd_ele;

void traverse(Node *root)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;

    q.push({root, 0});
    hd_ele[0] = root->data;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            Node *t = q.front().first;
            int lvl = q.front().second;

            if (hd_ele.find(lvl) == hd_ele.end())
                hd_ele[lvl] = t->data;

            q.pop();

            if (t->left)
                q.push({t->left, lvl - 1});
            if (t->right)
                q.push({t->right, lvl + 1});
        }
    }
}

vector<int> topView(Node *root)
{
    if (root == NULL)
        return {};

    traverse(root);

    vector<int> ans;

    for (auto it : hd_ele)
    {
        ans.push_back(it.second);
    }

    return ans;
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

    vector<int> v = topView(root);

    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}