// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// https://discuss.geeksforgeeks.org/comment/bdb9c2b72c3709a80b7392455be84c7e

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001];

int rec(string &S1, string &S2, int n, int m, int i, int j)
{
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0;
    if (S1[i] == S2[j])
        take = 1 + rec(S1, S2, n, m, i + 1, j + 1);

    int skipFirst = rec(S1, S2, n, m, i + 1, j);
    int skipSec = rec(S1, S2, n, m, i, j + 1);

    return dp[i][j] = max({skipFirst, skipSec, take});
}

int iter(string &S1, string &S2, int n, int m)
{
    int iterDP[n + 1][m + 1];

    for (int i = 0; i <= n; ++i)
        iterDP[i][0] = 0;

    for (int j = 0; j <= m; ++j)
        iterDP[0][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (S1[i - 1] == S2[j - 1])
                iterDP[i][j] = 1 + iterDP[i - 1][j - 1];
            else
                iterDP[i][j] = max(iterDP[i][j - 1], iterDP[i - 1][j]);
        }
    }

    return iterDP[n][m];
}

int lcs(int x, int y, string &S1, string &S2)
{
    // recursive dp
    // memset(dp, -1, sizeof dp);
    // return rec(S1, S2, x, y, 0, 0);

    // iterative dp
    return iter(S1, S2, x, y);
}

int main()
{
    string S1 = "ABCDGH";
    string S2 = "ACDGHR";

    int n = S1.length();
    int m = S2.length();

    cout << lcs(n, m, S1, S2) << "\n";

    return 0;
}