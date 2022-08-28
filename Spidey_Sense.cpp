// https://practice.geeksforgeeks.org/problems/spidey-sense5556/1?page=2&difficulty[]=0&difficulty[]=1&status[]=unsolved&sortBy=accuracy

// https://discuss.geeksforgeeks.org/comment/f5e5de310b1a07d52469d9767478b0c6

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> findDistance(vector<vector<char>> &grid, int rows, int cols)
{
    vector<vector<int>> ans(rows, vector<int>(cols, 0));

    queue<int> q;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 'O')
            {
                ans[i][j] = INT_MAX;
            }
            else if (grid[i][j] == 'W')
                ans[i][j] = -1;
            else if (grid[i][j] == 'B')
            {
                ans[i][j] = 0;
                q.push(i * cols + j);
            }
        }
    }

    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int curCell = q.front();
            q.pop();

            int curCellX = curCell / cols;
            int curCellY = curCell % cols;

            for (int k = 0; k < dirs.size(); ++k)
            {
                int nextCellX = curCellX + dirs[k][0];
                int nextCellY = curCellY + dirs[k][1];

                if (nextCellX >= 0 && nextCellX < rows && nextCellY >= 0 && nextCellY < cols && ans[nextCellX][nextCellY] == INT_MAX)
                {
                    ans[nextCellX][nextCellY] = level + 1;
                    q.push(nextCellX * cols + nextCellY);
                }
            }
        }
        ++level;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (ans[i][j] == INT_MAX)
                ans[i][j] = -1;
        }
    }

    return ans;
}

int main()
{
    vector<vector<char>> grid = {
        {'O', 'O', 'O'},
        {'W', 'B', 'B'},
        {'W', 'O', 'O'},
    };

    vector<vector<int>> ans = findDistance(grid, 3, 3);

    for (vector<int> &v : ans)
    {
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}