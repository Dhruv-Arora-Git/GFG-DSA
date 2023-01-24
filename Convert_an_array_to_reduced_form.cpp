// https://practice.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1

// https://discuss.geeksforgeeks.org/comment/077ef66963d519f67403e3134801f7a9

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void convert(int arr[], int n)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i)
        v.push_back({arr[i], i});

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
        arr[v[i].second] = i;
}

int main()
{
    int arr[] = {10, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    convert(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}