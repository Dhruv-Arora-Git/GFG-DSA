// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

// https://discuss.geeksforgeeks.org/comment/de27ec6682766a7f23b1a62262ed9861

#include <iostream>
#include <unordered_set>

using namespace std;

// ---------------------------
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
// ---------------------------

Node *removeDuplicates(Node *head)
{
    unordered_set<int> seen;

    Node *itr = head, *prev = NULL;

    while (itr)
    {
        if (seen.find(itr->data) != seen.end())
        {
            Node *nxt = itr->next;
            itr->next = NULL;
            delete itr;
            prev->next = nxt;
            itr = nxt;
        }
        else
        {
            seen.insert(itr->data);
            prev = itr;
            itr = itr->next;
        }
    }

    return head;
}

int main()
{
    // 5 -> 2 -> 2 -> 4
    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    head = removeDuplicates(head);

    Node *itr = head;
    while (itr)
    {
        cout << itr->data << " -> ";
        itr = itr->next;
    }
    cout << "NULL\n";

    return 0;
}