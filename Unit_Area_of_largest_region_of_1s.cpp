// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

// https://discuss.geeksforgeeks.org/comment/7ec6782debc52301e01ae41596f47360

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int rows, int cols, int &area)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        return;

    grid[i][j] = 0; // visited
    ++area;

    dfs(grid, i + 1, j, rows, cols, area);
    dfs(grid, i - 1, j, rows, cols, area);
    dfs(grid, i, j + 1, rows, cols, area);
    dfs(grid, i, j - 1, rows, cols, area);
    dfs(grid, i + 1, j + 1, rows, cols, area);
    dfs(grid, i - 1, j + 1, rows, cols, area);
    dfs(grid, i + 1, j - 1, rows, cols, area);
    dfs(grid, i - 1, j - 1, rows, cols, area);
}

int findMaxArea(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int mxArea = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1)
            {
                int area = 0;
                dfs(grid, i, j, rows, cols, area);
                mxArea = max(mxArea, area);
            }
        }
    }
    return mxArea;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
    };

    cout << findMaxArea(grid) << "\n";

    return 0;
}