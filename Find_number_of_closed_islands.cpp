// https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1

// https://discuss.geeksforgeeks.org/comment/81f052097eb96f0fe2b5d695d7f6525e

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& mat, int i, int j, int &n, int &m, bool &flag) {
        if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0)
            return;
            
        if((i == 0 || i == n - 1) || (j == 0 || j == m - 1) && mat[i][j] == 1)
            flag = false;
        
           
        mat[i][j] = 0;
        
        dfs(mat, i + 1, j, n, m, flag);
        dfs(mat, i - 1, j, n, m, flag);
        dfs(mat, i, j + 1, n, m, flag);
        dfs(mat, i, j - 1, n, m, flag);
    }


int closedIslands(vector<vector<int>>& mat, int n, int m) {
    int islands = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(mat[i][j] == 1) {
                bool flag = true;
                dfs(mat, i, j, n, m, flag);

                if(flag)
                    ++islands;
            }
        }
    }
    
    return islands;
}

int main() {
	
	vector<vector<int>> mat = {
								{0, 0, 0, 0, 0, 0, 0, 1}, 
					           	{0, 1, 1, 1, 1, 0, 0, 1}, 
					           	{0, 1, 0, 1, 0, 0, 0, 1}, 
					           	{0, 1, 1, 1, 1, 0, 1, 0}, 
					           	{1, 0, 0, 0, 0, 1, 0, 1}
					       };
	

	cout << closedIslands(mat, 5, 8) << '\n';

	return 0;
}
    