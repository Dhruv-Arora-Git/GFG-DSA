// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// https://discuss.geeksforgeeks.org/comment/a319b0b3c78fae912b963fe8f7352ee3

#include <iostream>
using namespace std;

// --------------------------------------------
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
// --------------------------------------------

Node *segregate(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    while (head)
    {
        if (head->data == 0)
        {
            zeroTail->next = head;
            zeroTail = zeroTail->next;
        }
        else if (head->data == 1)
        {
            oneTail->next = head;
            oneTail = oneTail->next;
        }
        else if (head->data == 2)
        {
            twoTail->next = head;
            twoTail = twoTail->next;
        }

        head = head->next;
    }

    if (oneHead->next)
    {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    twoTail->next = NULL;

    return zeroHead->next;
}

int main()
{
    // 1 -> 2 -> 0 -> 1 -> 2 -> 0
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    Node *itr = segregate(head);
    // 0 -> 0 -> 1 -> 1 -> 2 -> 2
    while (itr)
    {
        cout << itr->data << " -> ";
        itr = itr->next;
    }
    cout << "NULL\n";

    return 0;
}