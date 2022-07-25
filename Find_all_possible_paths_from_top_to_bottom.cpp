// https://practice.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1#

// https://discuss.geeksforgeeks.org/comment/6847476d1e1062f8102df01fdc9e7303

#include <iostream>
#include <vector>

using namespace std;

void find(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int> path, vector<vector<int>> &paths)
{
    if (i == n - 1 && j == m - 1)
    {
        path.push_back(grid[i][j]);
        paths.push_back(path);
        return;
    }

    path.push_back(grid[i][j]);

    if (i < n - 1)
        find(i + 1, j, n, m, grid, path, paths);

    if (j < m - 1)
        find(i, j + 1, n, m, grid, path, paths);
}

vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
{
    vector<int> v;

    vector<vector<int>> paths;
    find(0, 0, n, m, grid, v, paths);

    return paths;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};

    vector<vector<int>> paths = findAllPossiblePaths(2, 3, grid);

    for (auto &path : paths)
    {
        for (auto &i : path)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}