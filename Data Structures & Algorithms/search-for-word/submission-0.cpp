class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (m, false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (dfs(board, visited, word, n, m, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word,
        int n, int m, int i, int j, int k) {
        if (k == word.size())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        cout<<k<<endl;
        cout<<board[i][j]<<endl;
        if (board[i][j] == word[k] && visited[i][j] == false) {
            visited[i][j] = true;
            // cout<<"Came here"<<endl;
            if (dfs(board, visited, word, n, m, i, j-1, k+1) ||
             dfs(board, visited, word, n, m, i, j+1, k+1) || 
             dfs(board, visited, word, n, m, i-1, j, k+1) || 
             dfs(board, visited, word, n, m, i+1, j, k+1))
                return true;
            else
                visited[i][j] = false;
        }
        // visited[i][j] = false;
        return false;
    }
};
