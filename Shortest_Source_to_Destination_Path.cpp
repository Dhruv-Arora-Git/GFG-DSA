// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

// https://discuss.geeksforgeeks.org/comment/ececb7d8db7825aa930062c19a43677f

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y)
{
    if (A[0][0] == 0)
        return -1;

    queue<int> q;
    vector<vector<int>> visited(n, vector<int>(m, false));
    // can use q.push(0) but just to follow the formula x * m + y
    q.push(0 * m + 0); // source node

    int level = 0;

    vector<vector<int>> dirs = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0},
    };

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int curr = q.front();
            q.pop();
            int x = curr / m, y = curr % m;

            // checking for up, down, left & right
            for (int k = 0; k < dirs.size(); ++k)
            {
                int _x = x + dirs[k][0], _y = y + dirs[k][1];

                if (_x >= 0 && _x < n && _y >= 0 && _y < m && visited[_x][_y] == false && A[_x][_y] == 1)
                {
                    if (_x == X && _y == Y) // we found the destination node
                        return level + 1;

                    q.push(_x * m + _y); // else push it into the queue
                    visited[_x][_y] = true;
                }
            }
        }
        ++level;
    }

    return -1;
}

int main()
{
    int n = 3, m = 4, X = 2, Y = 3;
    vector<vector<int>> A = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
    };

    cout << shortestDistance(n, m, A, X, Y) << "\n";

    return 0;
}