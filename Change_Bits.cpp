// https://practice.geeksforgeeks.org/problems/change-bits1538/1#

// https://discuss.geeksforgeeks.org/comment/21157c409d04739e03036edc095ca59a

#include <iostream>
#include <vector>

using namespace std;

vector<int> changeBits(int N)
{
    // answer array
    vector<int> ans;

    int temp = N;
    // calculating number of bits in N
    int cnt = 0;
    while (N)
    {
        ++cnt;
        N = N >> 1;
    }

    // as all bits should be 1, so cnt is our binary number
    // converting it to decimal
    int num = 0;
    int mul = 1;
    while (cnt--)
    {
        num += mul;
        mul *= 2;
    }

    ans.push_back(num - temp); // diff b/w them
    ans.push_back(num);        // decimal number with all 1 bits

    return ans;
}

int main()
{
    int N = 8;
    // cin >> N;
    vector<int> ans = changeBits(N);

    for (int &i : ans)
        cout << i << " ";

    cout << "\n";

    return 0;
}