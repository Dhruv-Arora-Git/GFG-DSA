// https://practice.geeksforgeeks.org/problems/45fa306a9116332ece4cecdaedf50f140bd252d4/1

// https://discuss.geeksforgeeks.org/comment/b262a0687461167c3b94325b24788dc3

// https://discuss.geeksforgeeks.org/comment/48ead93a9e79eaeedd0dddb801036ad6

#include <iostream>
using namespace std;

int maxInstance(string s)
{
    int arr[26] = {0};

    for (char &ch : s)
        if (ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            ++arr[ch - 'a'];

    int minVal = 1e9;

    arr['l' - 'a'] /= 2;
    arr['o' - 'a'] /= 2;

    for (int i = 0; i < 26; ++i)
        if (i == 1 || i == 0 || i == 11 || i == 14 || i == 13)
            minVal = min(minVal, arr[i]);

    return minVal;
}

int main()
{
    string s = "loonbalxballpoon";
    cout << maxInstance(s) << "\n";

    return 0;
}