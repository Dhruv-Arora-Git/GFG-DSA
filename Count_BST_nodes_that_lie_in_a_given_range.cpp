// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

// https://discuss.geeksforgeeks.org/comment/af23903cc4259c19a4dd4cf33e096b48

#include <iostream>
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


int getCount(Node *root, int l, int h) {
    if(root == NULL)
        return 0;
    
    // check and count node, it's left and it's right
    return ((root->data >= l && root->data <= h) ? 1 : 0)
        + getCount(root->left, l, h)
        + getCount(root->right, l, h);
}

int main()
{
    /*
          10
         /  \
        5    50
       /    /  \
      1    40  100

    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5, h = 45;
    cout << getCount(root, l, h) << "\n";
    return 0;                       
}