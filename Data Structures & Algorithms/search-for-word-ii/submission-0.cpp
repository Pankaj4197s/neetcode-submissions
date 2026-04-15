class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto w : words)
            if (exist(board, w))
                res.push_back(w);
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        // Frequency pruning
        unordered_map<char,int> countBoard, countWord;
        for (auto &row : board)
            for (auto &ch : row) countBoard[ch]++;
        for (auto &ch : word) countWord[ch]++;
        for (auto &p : countWord)
            if (countBoard[p.first] < p.second) return false;

        // Reverse word if ending char is rarer
        if (countBoard[word[0]] > countBoard[word.back()])
            reverse(word.begin(), word.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, int k, const string &word) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (board[i][j] != word[k]) return false;

        char tmp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool found = dfs(board, i+1, j, k+1, word) ||
                     dfs(board, i-1, j, k+1, word) ||
                     dfs(board, i, j+1, k+1, word) ||
                     dfs(board, i, j-1, k+1, word);

        board[i][j] = tmp; // restore
        return found;
    }
};
