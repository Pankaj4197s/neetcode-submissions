class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        dfs(ans, board, 0);
        return ans;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& board, int r) {
        if (r == board.size()) {
            ans.push_back(board);
            return;
        }
        for(int c=0;c<board.size();c++) {
            if (isSafe(board, r, c)) {
                board[r][c] = 'Q';
                dfs(ans, board, r+1);
                board[r][c] = '.';
            }
        }
        // if (i < 0 || i >= n || j < 0 || j >= n) {
        //     return false;
        // }
        // if (valid[i][j]) {
        //     board[i][j] = "Q";
        //     for(int k=0;k<n;k++)
        //         valid[k][j] = false;
        //     for(int k=0;k<n;k++)
        //         valid[i][k] = false;
        //     for(int k=i;k<n;k++)
        //         for(int l=j;l<n;l++)
        //             valid[k][l] = false;
        //     for(int k=i;k>=0;k--)
        //         for(int l=j;l>=0;l--)
        //             valid[k][l] = false;
        //     for(int k=i;k<n;k++)
        //         for(int l=j;l>=0;l--)
        //             valid[k][l] = false;
        //     for(int k=i;k>=0;k--)
        //         for(int l=j;l<n;l++)
        //             valid[k][l] = false;
        //     if (dfs(board, valid, i, j+1, n-1) || 
        //     dfs(board, valid, i, j-1, n-1) ||
        //     dfs(board, valid, i+1, j+1, n-1) ||
        //     dfs(board, valid, i+1, j, n-1) ||
        //     dfs(board, valid, i+1, j-1, n-1) ||
        //     dfs(board, valid, i-1, j+1, n-1) ||
        //     dfs(board, valid, i-1, j, n-1) ||
        //     dfs(board, valid, i-1, j-1, n-1))
        //         return true;
        //     // else {
        //         board[i][j] = ".";
        //         for(int k=0;k<n;k++)
        //             valid[k][j] = true;
        //         for(int k=0;k<n;k++)
        //             valid[i][k] = true;
        //         for(int k=i;k<n;k++)
        //             for(int l=j;l<n;l++)
        //                 valid[k][l] = true;
        //         for(int k=i;k>=0;k--)
        //             for(int l=j;l>=0;l--)
        //                 valid[k][l] = true;
        //         for(int k=i;k<n;k++)
        //             for(int l=j;l>=0;l--)
        //                 valid[k][l] = true;
        //         for(int k=i;k>=0;k--)
        //             for(int l=j;l<n;l++)
        //                 valid[k][l] = true;
        //         // if (dfs(board, valid, i, j+1, n) || 
        //         //     dfs(board, valid, i, j-1, n) ||
        //         //     dfs(board, valid, i+1, j+1, n) ||
        //         //     dfs(board, valid, i+1, j, n) ||
        //         //     dfs(board, valid, i+1, j-1, n) ||
        //         //     dfs(board, valid, i-1, j+1, n) ||
        //         //     dfs(board, valid, i-1, j, n) ||
        //         //     dfs(board, valid, i-1, j-1, n))
        //         //         return true;
        //     // }
        // }
        // return false;
    }

    bool isSafe(vector<string>& board, int r, int c) {
        for (int i = r-1;i>=0;i--) {
            if (board[i][c] == 'Q')
                return false;
        }
        for (int i = r-1, j=c-1;i>=0 && j>=0;i--,j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = r-1, j=c+1;i>=0 && j<board.size();i--,j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
