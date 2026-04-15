class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto time : times)
            adj[time[0]].push_back({time[1], time[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[0] = -1;
        pq.push({k, 0});
        dist[k] = 0;

        while(!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int curr = top.first;
            int currDist = top.second;
            if (currDist > dist[curr])
                continue;

            for(auto v : adj[curr]) {
                if (currDist + v.second < dist[v.first]) {
                    dist[v.first] = currDist + v.second;
                    pq.push({v.first, dist[v.first]});
                }
            }
        }

        int minTime = INT_MIN;
        for(auto d : dist) {
            cout<<d<<endl;
            minTime = max(minTime, d);
            if (d == INT_MAX)
                return -1;
        }
        
        return minTime;
    }
};
