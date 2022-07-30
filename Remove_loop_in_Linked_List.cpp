// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&status[]=unsolved&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/e46f76c0ea3679ec22fe6e210c8a1b56

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

void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    unordered_set<Node *> hashSet;
    Node *prev = NULL;

    while (true)
    {
        if (hashSet.count(head) > 0)
        {
            prev->next = NULL;
            break;
        }

        if (head == NULL)
            break;

        hashSet.insert(head);
        prev = head;
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // add loop here
    head->next->next->next = head->next;

    removeLoop(head);

    // now the loop is removed, hence, we can print the linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}