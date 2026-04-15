class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int depth = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (grid[i][j])
                    depth = max(depth, dfs(grid, visited, i, j, n, m));
        return depth;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        int res = 0;
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j])
            return res;
        if (grid[i][j]) {
            res++;
            visited[i][j] = true;
            res += dfs(grid, visited, i+1, j, n, m);
            res += dfs(grid, visited, i-1, j, n, m);
            res += dfs(grid, visited, i, j+1, n, m);
            res += dfs(grid, visited, i, j-1, n, m);
        }  
        return res;
    }
};
