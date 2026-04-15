class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            if (board[0][i] == 'O')
                q.push({0, i});
            if (board[m-1][i] == 'O')
                q.push({m-1, i});
        }
        for(int i=0;i<m;i++) {
            if (board[i][0] == 'O')
                q.push({i, 0});
            if (board[i][n-1] == 'O')
                q.push({i, n-1});
        }
        cout<<q.size()<<endl;
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            if (board[i][j] == 'O') {
                board[i][j] = '-';
                for(int d=0;d<4;d++) {
                    int nx = dir[d].first;
                    int ny = dir[d].second;
                    int x = i+nx;
                    int y = j+ny;
                    if (isValid(x, y, m, n) && board[x][y] == 'O')
                        q.push({x,y});
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (board[i][j] == '-')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }  
    }

    bool isValid(int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
};
