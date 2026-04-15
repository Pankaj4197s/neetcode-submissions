class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        // queue<tuple<int, int, int>> pq;
        dist[src] = 0;
        pq.push({src, 0, 0});
        // int stops = 0;
        while(!pq.empty()) {
            // tuple<int, int, int> top = pq.top();
            // int curr = top.first;
            // int curr_cost = top.second;
            // int stops = top.third;
            auto [curr, curr_cost, stops] = pq.top();
            pq.pop();
            if (stops > k)
                continue;
            // if (curr_cost > dist[curr])
                // continue;
            // stops++;
            for(auto f : flights) {
                int src = f[0];
                int dest = f[1];
                int cost = f[2];
                if (src == curr && curr_cost + cost < dist[dest]) {
                    dist[dest] = curr_cost + cost;
                    pq.push({dest, curr_cost + cost, stops + 1});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};