class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's Algorithm
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i=0;i<n;i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }    
        }

        int res = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        minH.push({0, 0});
        while(!minH.empty()) {
            auto curr = minH.top();
            minH.pop();
            int cost = curr.first;
            int i = curr.second;
            if (visited[i])
                continue;
            res += cost;
            visited[i] = true;
            for(auto v : adj[i]) {
                if (!visited[v.second]) {
                    minH.push(v);
                }
            }
        }
        return res;
    }
};
