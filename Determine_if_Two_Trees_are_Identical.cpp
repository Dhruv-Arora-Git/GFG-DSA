// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/0/#

// https://discuss.geeksforgeeks.org/comment/7264b82a5ef7b4e32da62136695af923

#include <iostream>
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

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    // check root, left and right
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    cout << boolalpha << isIdentical(root1, root2) << "\n";

    return 0;
}