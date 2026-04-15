class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman Ford
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i <= k; i++) {
            vector<int> tmpDist = dist;
            for(const auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if (dist[s] == INT_MAX)
                    continue;
                if (dist[s] + p < tmpDist[d])
                    tmpDist[d] = dist[s] + p;
            }
            dist = tmpDist;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};