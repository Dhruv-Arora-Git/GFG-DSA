// https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1

// https://discuss.geeksforgeeks.org/comment/c5ef6f8b81f4a49ba5b8a5f3739b1dc9

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long long int minIncrements(vector<int> arr, int size)
{
    set<int> st;

    long long cost = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < size; ++i)
    {
        while (st.find(arr[i]) != st.end())
        {
            ++cost;
            ++arr[i];
        }

        st.insert(arr[i]);
    }

    return cost;
}

int main()
{
    vector<int> arr = {2, 2, 3, 5, 3, 7, 9, 5, 5, 5, 4, 8, 12};
    int size = arr.size();

    cout << minIncrements(arr, size) << "\n";

    return 0;
}