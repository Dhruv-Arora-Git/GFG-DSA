// https://practice.geeksforgeeks.org/problems/common-elements1132/1

// https://discuss.geeksforgeeks.org/comment/4ba1233bce6d7e711fbb849b9c6f5122

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> freq;

    vector<int> ans;

    for (int i = 0; i < n1; ++i)
        freq[A[i]] = 1;

    for (int i = 0; i < n2; ++i)
    {
        if (freq.find(B[i]) != freq.end())
        {
            if (freq.find(B[i])->second == 1)
            {
                freq[B[i]] = 2;
            }
        }

        else
            freq[B[i]] = INT_MIN;
    }

    for (int i = 0; i < n3; ++i)
    {
        if (freq.find(C[i]) != freq.end())
        {
            if (freq.find(C[i])->second == 2)
            {
                freq[C[i]] = 3;
            }
        }

        else
            freq[C[i]] = INT_MIN;
    }

    for (auto &it : freq)
    {
        if (it.second == 3)
            ans.push_back(it.first);
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 80};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    vector<int> ans = commonElements(A, B, C, n1, n2, n3);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}