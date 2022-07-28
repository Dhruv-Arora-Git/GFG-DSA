// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?page=1&difficulty[]=1&difficulty[]=2&status[]=unsolved&sortBy=submissions

// https://discuss.geeksforgeeks.org/comment/41371f7428f9b209c2476e6d267df97a

#include <iostream>
#include <unordered_map>

using namespace std;

int *findTwoElement(int *arr, int n)
{
    unordered_map<int, int> mp;

    long long sum = 0;
    long long realSum = (n * (n + 1ll)) / 2;

    int *ans = new int[2];

    for (int i = 0; i < n; ++i)
    {
        if (++mp[arr[i]] == 2)
        {
            ans[0] = arr[i]; // we found the duplicate
            sum -= arr[i];   // not to add it into the sum twice
        }
        sum += arr[i];
    }

    ans[1] = realSum - sum; // missing num

    return ans;
}
int main()
{
    int n = 3;
    int arr[n] = {1, 3, 3};

    int *ans = findTwoElement(arr, n);

    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}