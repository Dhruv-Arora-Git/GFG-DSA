// https://practice.geeksforgeeks.org/problems/adding-array-element4756/1

// https://discuss.geeksforgeeks.org/comment/198fe5ceb8b87afafaf6ee62f15aac92

#include <iostream>
#include <queue>

using namespace std;

int minOperations(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap

    // adding all elements < k to the minHeap (pq)
    for (int i = 0; i < n; ++i)
        if (arr[i] < k)
            pq.push(arr[i]);

    int operations = 0;

    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        // if pq empty, just return (operations + 1)
        if (pq.empty())
            return ++operations;

        int sec = pq.top();
        pq.pop();

        if (first + sec == k) // don't push it into pq
            ++operations;

        if (first + sec < k)
        {
            ++operations;
            pq.push(first + sec);
        }
    }
    return operations;
}

int main()
{
    int n = 6, k = 6;
    int arr[n] = {1, 10, 12, 9, 2, 3};

    cout << minOperations(arr, n, k) << "\n";

    return 0;
}