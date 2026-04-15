class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int val = dfs(i, j, n, m, matrix, dp);
                res = max(res, val);
            }
        }
        return res;
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != 0)
            return dp[i][j];
        int res = 1;
        if (i+1 < n && matrix[i+1][j] < matrix[i][j])
            res = max(res, 1 + dfs(i+1, j, n, m, matrix, dp));
        if (i-1 >= 0 && matrix[i-1][j] < matrix[i][j])
            res = max(res, 1 + dfs(i-1, j, n, m, matrix, dp));
        if (j+1 < m && matrix[i][j+1] < matrix[i][j])
            res = max(res, 1 + dfs(i, j+1, n, m, matrix, dp));
        if (j-1 >= 0 && matrix[i][j-1] < matrix[i][j])
            res = max(res, 1 + dfs(i, j-1, n, m, matrix, dp));
        dp[i][j] = res;
        return res;
    }
};
