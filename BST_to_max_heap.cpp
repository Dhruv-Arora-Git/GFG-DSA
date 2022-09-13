// https://practice.geeksforgeeks.org//bst-to-max-heap/1

// https://discuss.geeksforgeeks.org/comment/69354de5595976dd446f7397794da84e

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node() {}
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void postorder(Node *root, vector<int> &v, int &i)
{
    if (!root)
        return;

    postorder(root->left, v, i);
    postorder(root->right, v, i);
    root->data = v[i++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> v;
    inorder(root, v);
    int i = 0;
    postorder(root, v, i);
}

void printHeap(Node *root)
{
    if (!root)
        return;

    printHeap(root->left);
    printHeap(root->right);
    cout << root->data << " ";
}

int main()
{
    /*
                 4
               /   \
              2     6
            /  \   /  \
           1    3  5   7
    */
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);
    /* O/P: 1 2 3 4 5 6 7
               7
             /   \
            3     6
          /   \  /  \
         1    2 4    5
    */
    printHeap(root);
    cout << "\n";
    return 0;
}