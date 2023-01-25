// https://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1

// https://discuss.geeksforgeeks.org/comment/20dae28edf26405c55c306ef380c9e41

#include <iostream>
using namespace std;

int minDist(int a[], int n, int x, int y)
{
    int first = -1, sec = -1;

    int mn = 1e9;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == x)
            first = i;

        if (a[i] == y)
            sec = i;

        if (first != -1 && sec != -1)
            mn = min(mn, abs(sec - first));
    }

    if (first == -1 || sec == -1)
        return -1;

    return mn;
}

int main()
{
    int arr[] = {1, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 1, y = 2;

    cout << minDist(arr, n, x, y) << "\n";

    return 0;
}