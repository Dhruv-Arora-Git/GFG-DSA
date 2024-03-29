// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

// https://discuss.geeksforgeeks.org/comment/aaba50494dd9bffe3ec447b9c329db2a

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> v(n, vector<int>(m, INT_MAX));

    if (n == 1 && m == 1)
    {
        if (grid[0][0] == 1)
            v[0][0] = 0;

        return v;
    }

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                q.push(i * m + j);
                vis[i][j] = 1;
                v[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    int level = 1;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int currCell = q.front();
            q.pop();
            int currX = currCell / m;
            int currY = currCell % m;

            for (int i = 0; i < 4; ++i)
            {
                int nextX = currX + dirs[i][0];
                int nextY = currY + dirs[i][1];
                if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m)
                {
                    if (!vis[nextX][nextY] && grid[nextX][nextY] == 0)
                    {
                        v[nextX][nextY] = level;
                        vis[nextX][nextY] = true;
                        q.push(nextX * m + nextY);
                    }
                }
            }
        }
        ++level;
    }

    return v;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
    };

    vector<vector<int>> v = nearest(grid);

    for (const vector<int> &row : v)
    {
        for (const int &i : row)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}