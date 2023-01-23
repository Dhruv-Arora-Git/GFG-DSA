// https://practice.geeksforgeeks.org/problems/466faca80c3e86f13880710491c634d26abd44a7/1

// https://discuss.geeksforgeeks.org/comment/3bc1ef3f773c23cf06118cf5ac9bb8fa

#include <iostream>
using namespace std;

string removePair(string s)
{
    string stk;
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        if (stk.empty() || stk.back() != s[i])
            stk.push_back(s[i]);
        else
            stk.pop_back();
    }

    return stk.size() == 0 ? "-1" : stk;
}

int main()
{
    string s = "aaabbaaccd";
    cout << removePair(s) << "\n";

    return 0;
}