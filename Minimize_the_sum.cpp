// https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1

// https://discuss.geeksforgeeks.org/comment/9c351de074def06d6ac931792a182d56

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minimizeSum(int size, vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    int sum = 0;

    while (minHeap.size() > 1)
    {
        int firstMin = minHeap.top();
        minHeap.pop();

        int secondMin = minHeap.top();
        minHeap.pop();

        sum += (firstMin + secondMin);

        minHeap.push(firstMin + secondMin);
    }

    return sum;
}

int main()
{
    // vector<int> arr = {2, 2, 3, 5, 3, 7, 9, 5, 5, 5, 4, 8, 12}; // case to test
    vector<int> arr = {1, 3, 7, 5, 6};
    int size = arr.size();

    cout << minimizeSum(size, arr) << "\n";

    return 0;
}