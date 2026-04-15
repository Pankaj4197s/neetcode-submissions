class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int depth = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (grid[i][j])
                    depth = max(depth, dfs(grid, i, j, n, m));
        return depth;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        int res = 0;
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return res;
        if (grid[i][j]) {
            res++;
            grid[i][j] = 0;
            res += dfs(grid, i+1, j, n, m);
            res += dfs(grid, i-1, j, n, m);
            res += dfs(grid, i, j+1, n, m);
            res += dfs(grid, i, j-1, n, m);
        }  
        return res;
    }
};
