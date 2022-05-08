#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> levelOrder(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();

        ans.push_back(t->data);

        if (t->left != NULL)
            q.push(t->left);

        if (t->right != NULL)
            q.push(t->right);
    }

    return ans;
}

int main()
{
    Node *root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 3;
    root->right = new Node();
    root->right->data = 2;

    vector<int> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}