class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});
        while(!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (dist[i][j] < d)
                continue;
            if (i-1 >= 0) {
                int t = max(d, grid[i-1][j]);
                if (t < dist[i-1][j]) {
                    dist[i-1][j] = t;
                    pq.push({dist[i-1][j], i-1, j});
                }
            }
            if (j-1 >= 0) {
                int t = max(d, grid[i][j-1]);
                if (t < dist[i][j-1]) {
                    dist[i][j-1] = t;
                    pq.push({dist[i][j-1], i, j-1});
                }
            }
            if (i+1 < n) {
                int t = max(d, grid[i+1][j]);
                if (t < dist[i+1][j]) {
                    dist[i+1][j] = t;
                    pq.push({dist[i+1][j], i+1, j});
                }
            }
            if (j+1 < n) {
                int t = max(d, grid[i][j+1]);
                if (t < dist[i][j+1]) {
                    dist[i][j+1] = t;
                    pq.push({dist[i][j+1], i, j+1});
                }
            }
        }
        return dist[n-1][n-1];
    }
};
