// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// https://discuss.geeksforgeeks.org/comment/709face14c80b021bb9af77cd51b558c

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> v;

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *tail = temp;

    while (head->data < tail->data)
    {
        int sum = head->data + tail->data;

        if (sum > target)
            tail = tail->prev;
        else if (sum < target)
            head = head->next;
        else
        {
            v.push_back({head->data, tail->data});
            head = head->next;
            tail = tail->prev;
        }
    }
    return v;
}

int main()
{
    // 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    int target = 7;

    vector<pair<int, int>> v = findPairsWithGivenSum(head, target);

    for (auto &i : v)
        cout << "{" << i.first << ", " << i.second << "}, ";

    cout << "\n";
    return 0;
}