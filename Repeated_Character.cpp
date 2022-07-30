// https://practice.geeksforgeeks.org/problems/repeated-character2058/1

// https://discuss.geeksforgeeks.org/comment/9a3ca5fa88bd634ce7a487f6557986ec

#include <iostream>
#include <vector>

using namespace std;

char firstRep(string s)
{
    vector<int> cnt(26, 0);

    for (const char &c : s)
        ++cnt[c - 'a'];

    for (const char &c : s)
        if (cnt[c - 'a'] > 1)
            return c;

    return '#';
}
int main()
{
    string s = "geeksforgeeks";

    cout << firstRep(s) << "\n";

    return 0;
}