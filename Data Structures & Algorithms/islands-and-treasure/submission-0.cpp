class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dx[4] = {0, 0, 1,-1};
        int dy[4] = {1, -1, 0, 0};
        int INF = 2147483647;
        vector<vector<int>> heights(r, vector<int> (c, -1));
        queue<pair<int, int>> q;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    heights[i][j] = 0;
                }
            }
        }
        int height = 1;
        while(!q.empty()) {
            int neighbors = q.size();
            while(neighbors) {
                pair<int, int> curr = q.front();
                q.pop();
                for(int d=0;d<4;d++) {
                    pair<int, int> nextCell = {curr.first + dx[d], curr.second + dy[d]};
                    if (nextCell.first >= 0 && nextCell.first < r && nextCell.second >= 0 && nextCell.second < c 
                    && heights[nextCell.first][nextCell.second] == -1 && grid[nextCell.first][nextCell.second] == INF) {
                        heights[nextCell.first][nextCell.second] = height;
                        grid[nextCell.first][nextCell.second] = height;
                        q.push({nextCell.first,nextCell.second});
                    }
                }
                neighbors--;
            }
            height++;
        }
        // grid = heights;
    }
};