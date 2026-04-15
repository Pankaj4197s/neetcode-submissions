class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return boxValid(board) && horValid(board) && verValid(board);
    } 
    
    bool boxValid(vector<vector<char>>& board) {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                int k = i*3;
                int l = j*3;
                bool sbvalid = smallBoxValid(board, k, l);
                if (!sbvalid)
                    return false;
            }
        }
        return true;
    }
    
    bool smallBoxValid(vector<vector<char>>& board, int k, int l) {
        vector<int> count(9, -1);
        for(int i=k;i<k+3;i++) {
            for(int j=l;j<l+3;j++) {
                char ch = board[i][j];
                if (ch != '.' ) {
                    int num = ch - '0' - 1;
                    if (count[num] == -1) {
                        count[num] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool horValid(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) {
            bool hlValid = horLineValid(board, i);
            if (!hlValid)
                return false;
        }
        return true;
    }
    
    bool horLineValid(vector<vector<char>>& board, int k) {
        vector<int> count(9, -1);
        for(int j=0;j<9;j++) {
            char ch = board[k][j];
            if (ch != '.' ) {
                int num = ch - '0' - 1;
                if (count[num] == -1) {
                    count[num] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool verValid(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) {
            bool vlValid = verLineValid(board, i);
            if (!vlValid)
                return false;
        }
        return true;
    }
    
    bool verLineValid(vector<vector<char>>& board, int k) {
        vector<int> count(9, -1);
        for(int j=0;j<9;j++) {
            char ch = board[j][k];
            if (ch != '.' ) {
                int num = ch - '0' - 1;
                if (count[num] == -1) {
                    count[num] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};