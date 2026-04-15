class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({src, 0, 0});    
        while(!pq.empty()) {
            auto [curr, curr_cost, stops] = pq.top();
            pq.pop();
            if (stops > k)
                continue;
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