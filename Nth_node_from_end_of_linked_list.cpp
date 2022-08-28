// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// https://discuss.geeksforgeeks.org/comment/95214d26f2a2f054d02ac9ddcb16a969

#include <iostream>
#include <unordered_set>

using namespace std;

// --------------------------------

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// --------------------------------
int sizeOfLL(Node *head)
{
    int sz = 0;

    while (head != NULL)
    {
        ++sz;
        head = head->next;
    }

    return sz;
}

int getNthFromLast(Node *head, int n)
{
    int size = sizeOfLL(head);

    if (n > size)
        return -1;

    n = size - n; // ex - n = 2, size = 8, size - n = 6 (that we actually need)

    for (int i = 0; i < n; ++i)
    {
        head = head->next;
    }

    return head->data;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next->next->next = new Node(11);

    cout << getNthFromLast(head, 2) << "\n";

    return 0;
}
