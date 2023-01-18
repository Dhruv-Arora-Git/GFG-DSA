// https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1

// https://discuss.geeksforgeeks.org/comment/6292bf3cb78c881930ac97c4c2d373ac

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

int findFirstNode(Node *head)
{
    Node *slow = head, *fast = head, *itr = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            while (itr != slow)
            {
                itr = itr->next;
                slow = slow->next;
            }

            return itr->data;
        }
    }

    return -1;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // create loop 5 -> 3
    head->next->next->next->next->next = head->next->next;

    cout << findFirstNode(head) << "\n";
    return 0;
}