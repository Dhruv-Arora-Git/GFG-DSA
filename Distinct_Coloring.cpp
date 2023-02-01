// https://practice.geeksforgeeks.org/problems/844b4fdcd988ac5461324d62d43f7892749a113c/1

// https://discuss.geeksforgeeks.org/comment/9909194a6681e7b017c9994b68e2bd90

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;

long long rec(int i, int n, int r[], int g[], int b[], int prev)
{
    if (i == n)
        return 0;

    if (dp[prev][i] != -1)
        return dp[prev][i];

    long long takeRed = 1e18, takeGreen = 1e18, takeBlue = 1e18;

    if (prev == 0)
    {
        takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
        takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
        takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
    }

    if (prev == 1)
    {
        takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
        takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
    }

    if (prev == 2)
    {
        takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
        takeBlue = b[i] + rec(i + 1, n, r, g, b, 3);
    }

    if (prev == 3)
    {
        takeRed = r[i] + rec(i + 1, n, r, g, b, 1);
        takeGreen = g[i] + rec(i + 1, n, r, g, b, 2);
    }

    return dp[prev][i] = min(takeRed, min(takeGreen, takeBlue));
}

long long int distinctColoring(int n, int r[], int g[], int b[])
{
    dp = vector<vector<long long>>(4, vector<long long>(n, -1));

    return rec(0, n, r, g, b, 0);
}

int main()
{
    int n = 3;
    int r[] = {1, 1, 1};
    int g[] = {2, 2, 2};
    int b[] = {3, 3, 3};

    cout << distinctColoring(n, r, g, b) << "\n";
    return 0;
}