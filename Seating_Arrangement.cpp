// https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1

// https://discuss.geeksforgeeks.org/comment/6de5172bb6fdb06c6ea7b89d2ad50f07

#include <iostream>
#include <vector>

using namespace std;
bool is_possible_to_get_seats(int n, int m, vector<int> &arr)
{
    for (int i = 0; i < m && n > 0; ++i)
    {
        // starting case
        if (i == 0 && m >= 2 && arr[i] == 0 && arr[i + 1] == 0)
        {
            arr[0] = 1;
            --n;
        }

        // middle case
        else if (i == m - 2 && arr[m - 2] == 0 && arr[m - 1] == 0)
        {
            --n;
            arr[m - 1] = 1;
        }

        // ending case
        else if (arr[i] == 0 && arr[i - 1] == 0 && arr[i + 1] == 0)
        {
            arr[i] = 1;
            --n;
        }
    }

    return n == 0;
}
int main()
{
    vector<int> seats = {0, 0, 1, 0, 0, 0, 1};
    int m = seats.size();
    int n = 2;
    cout << (is_possible_to_get_seats(n, m, seats) ? "Yes" : "No") << "\n";
    return 0;
}