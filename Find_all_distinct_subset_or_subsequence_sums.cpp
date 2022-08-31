// https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1

// https://discuss.geeksforgeeks.org/comment/53b63fe9e10c3423021658f83f95c878

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

set<int> st;
vector<vector<int>> dp;

int subset(vector<int> &arr, int i, int sum)
{
    if (i >= arr.size())
    {
        st.insert(sum);
        return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    dp[i][sum] = subset(arr, i + 1, sum + arr[i]);
    dp[i][sum] = subset(arr, i + 1, sum);
}

vector<int> DistinctSum(vector<int> nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    dp = vector<vector<int>>(n, vector<int>(totalSum, -1));

    subset(nums, 0, 0);

    vector<int> v(st.begin(), st.end());

    return v;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<int> ans = DistinctSum(nums);

    for (int &i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}