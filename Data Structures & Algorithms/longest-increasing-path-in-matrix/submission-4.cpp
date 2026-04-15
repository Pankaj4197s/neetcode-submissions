class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<"curr : "<<matrix[i][j]<<endl;
                int val = dfs(i, j, n, m, matrix);
                res = max(res, val);
                cout<<"---"<<val<<endl;
            }
        }
        return res;
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix) {
        // if (dp[i][j] != 0)
        //     return dp[i][j];
        // if (visited[i][j])
            // return 0;
        // visited[i][j] = true;
        cout<<matrix[i][j]<<endl;
        int res = 1;
        if (i+1 < n && matrix[i+1][j] < matrix[i][j])
            res = max(res, 1 + dfs(i+1, j, n, m, matrix));
        if (i-1 >= 0 && matrix[i-1][j] < matrix[i][j])
            res = max(res, 1 + dfs(i-1, j, n, m, matrix));
        if (j+1 < m && matrix[i][j+1] < matrix[i][j])
            res = max(res, 1 + dfs(i, j+1, n, m, matrix));
        if (j-1 >= 0 && matrix[i][j-1] < matrix[i][j])
            res = max(res, 1 + dfs(i, j-1, n, m, matrix));
        return res;
    }
};
