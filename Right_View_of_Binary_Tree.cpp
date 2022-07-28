// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1?page=2&category%5B%5D=Tree&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/c568c0f00e20c7d6e5ed13831e1ca251

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// --------------------------------

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

// --------------------------------

vector<int> rightView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    queue<Node *> q;
    q.push(root);

    // Simple BFS
    while (!q.empty())
    {
        int sz = q.size();
        int t = -1;

        while (sz--)
        {
            Node *u = q.front();
            q.pop();
            t = u->data; // at last of each level traversal, it will have rightmost Node value

            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
        ans.push_back(t);
    }
    return ans;
}

int main()
{
    //     10
    //    /  \
    //   20  30
    //  /  \
    // 40  60

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // 10 30 60
    vector<int> ans = rightView(root);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}