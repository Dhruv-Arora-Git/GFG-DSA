// https://practice.geeksforgeeks.org/problems/bae68b4d6a2a77fb6bd459cf7447240919ebfbf5/1

// https://discuss.geeksforgeeks.org/comment/2574700afce6112a66d3ff13c0de2b73

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverse(Node *head, int k)
{
    int sz = k;
    Node *secHead = head;
    Node *tail = nullptr;
    while (sz--)
    {
        tail = secHead;
        secHead = secHead->next;
    }

    // break the list
    tail->next = NULL;

    // reverse first part
    Node *prev = NULL, *curr = head;
    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // reverse sec part
    Node *prev2 = NULL, *curr2 = secHead;
    while (curr2)
    {
        Node *nxt = curr2->next;
        curr2->next = prev2;
        prev2 = curr2;
        curr2 = nxt;
    }

    // join
    head->next = prev2;
    return tail;
}

int main()
{
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;

    Node *revHead = reverse(head, k);
    // 2 -> 1 -> 5 -> 4 -> 3 -> NULL
    while (revHead)
    {
        cout << revHead->data << " -> ";
        revHead = revHead->next;
    }
    cout << "NULL\n";
    return 0;
}