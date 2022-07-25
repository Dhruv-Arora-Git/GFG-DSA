// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&category%5B%5D=Tree&curated%5B%5D=1&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/c52961752d3f22ba4c05c3d0dbb1370a

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

vector<int> findSpiral(Node *root)
{
    if (!root)
        return {};

    vector<int> v;

    queue<Node *> q;
    q.push(root);

    int lvl = 0;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp;
        ++lvl;

        while (sz--)
        {
            Node *t = q.front();
            q.pop();
            temp.push_back(t->data);

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }

        if (lvl & 1)                           // odd level
            reverse(temp.begin(), temp.end()); // reverse the order

        v.insert(v.end(), temp.begin(), temp.end()); // insert into answer vector
    }
    return v;
}

int main()
{
    //        10
    //       /  \
    //      20  30
    //     / \ 
    //    40  60

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // 10 20 30 60 40
    vector<int> v = findSpiral(root);

    for (int &i : v)
        cout << i << " ";
    cout << "\n";

    return 0;
}