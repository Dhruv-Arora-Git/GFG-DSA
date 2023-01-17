// https://practice.geeksforgeeks.org/problems/6eb51dc638ee1b936f38d1ab4b2f7062d4425463/1

// https://discuss.geeksforgeeks.org/comment/44e0c2be80ce4b4b045fcf3aae0f681b

#include <iostream>
#include <algorithm>

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

int maxGcd = -1e9;
int maxNode = 0;

void dfs(Node *root)
{
    if (!root)
        return;

    if (root->left && root->right)
    {
        int gcd = __gcd(root->left->data, root->right->data);
        if (gcd >= maxGcd)
        {
            // check if same gcd, take max Node value
            maxNode = maxGcd == gcd ? max(root->data, maxNode) : root->data;
            maxGcd = gcd;
        }
    }

    dfs(root->left);
    dfs(root->right);
}

int maxGCD(Node *root)
{
    dfs(root);
    return maxNode;
}

// n b =
int main()
{
    /*
               4
              / \
             5   2
                / \
               3   1
              / \
             6   12
    */
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(1);
    root->right->left->right = new Node(6);
    root->right->left->left = new Node(12);

    cout << maxGCD(root) << "\n";

    return 0;
}