// https://practice.geeksforgeeks.org/problems/87f12e5c728d69a5322634776b54c75897d14daa/0/?category[]=Linked%20List&category[]=Linked%20List&page=2&query=category[]Linked%20Listpage2category[]Linked%20List#

// https://discuss.geeksforgeeks.org/comment/818970779fea09e9b95ac16b0b539700

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int countTriplets(struct Node *head, int x)
{
    vector<int> arr;
    Node *t = head;
    while (t != NULL)
    {
        arr.push_back(t->data);
        t = t->next;
    }

    sort(arr.begin(), arr.end());
    int cnt = 0, n = arr.size();

    for (int k = 0; k < n - 2; ++k)
    {
        int i = k + 1, j = n - 1;

        while (i < j)
        {
            int sum = arr[k] + arr[i] + arr[j];
            if (sum == x)
                ++cnt;

            if (sum <= x)
                ++i;
            else
                --j;
        }
    }

    return cnt;
}
int main()
{
    struct Node *head = NULL;
    // 1 -> 2 -> 4 -> 5 -> 6 -> 8 -> 9 -> X
    push(&head, 1);
    push(&head, 2);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 8);
    push(&head, 9);

    int x = 17;
    int cnt = countTriplets(head, x);
    cout << cnt << "\n";

    return 0;
}