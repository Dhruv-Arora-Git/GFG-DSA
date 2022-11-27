// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// https://discuss.geeksforgeeks.org/comment/f8048c4663d34ddd9f9d888371b2057b

#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> res; // for sorted output

void perm(string processed, string orig)
{
    if (orig.size() == 0)
    {
        res.insert(processed);
        return;
    }

    for (int i = 0; i < orig.size(); ++i)
    {
        // take out char at i and add it to processed
        string str = orig.substr(0, i) + orig.substr(i + 1);
        perm(processed + orig[i], str);
    }
}

vector<string> find_permutation(string &S)
{
    res.clear();

    perm("", S);

    vector<string> v;

    for (const string &s : res)
        v.push_back(s);

    return v;
}

int main()
{
    string str = "HARI";

    vector<string> v = find_permutation(str);

    for (const string &s : v)
        cout << s << "\n";

    return 0;
}