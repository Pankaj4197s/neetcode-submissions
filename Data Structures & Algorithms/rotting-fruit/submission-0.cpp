class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        vector<vector<int>> time(m, vector<int> (n, -1));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    time[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        if (cnt == 0)
            return 0;
        int level = 1;
        int last = -1;
        while(!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                pair<int, int> curr = q.front();
                q.pop();

                for(int d=0;d<4;d++) {
                    pair<int, int> next = {curr.first + dx[d], curr.second + dy[d]};

                    if (next.first >= 0 && next.second >= 0 && next.first < m && next.second < n
                        && grid[next.first][next.second] == 1 && time[next.first][next.second] == -1) {
                            time[next.first][next.second] = level;
                            cnt--;
                            q.push({next.first, next.second});
                            last = level;
                        }
                }
                qSize--;
            }
            level++;
        }
        if (cnt == 0)
            return last;
        return -1;
    }
};