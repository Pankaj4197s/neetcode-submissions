class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> adj(n, vector<int>());
        // vector<vector<int>> adj1(n, vector<int>());
        // vector<int> indegree(n, 0);
        // vector<int> indegree1(n, 0);
        // for(auto p : edges) {
        //     adj[p[1]].push_back(p[0]);
        //     adj1[p[0]].push_back(p[1]);
        //     indegree[p[0]]++;
        //     indegree1[p[1]]++;
        // }
        // queue<int> q;
        // queue<int> q1;
        // int n1 = n;
        // for (int i = 0; i < n; i++)
        //     if (indegree[i] == 0) 
        //         q.push(i);
        // while (!q.empty()) {
        //     int curr = q.front(); 
        //     q.pop(); 
        //     n--;
        //     for (auto next : adj[curr])
        //         if (--indegree[next] == 0) 
        //             q.push(next);
        // }
        // for (int i = 0; i < n1; i++)
        //     if (indegree1[i] == 0) 
        //         q1.push(i);
        // while (!q1.empty()) {
        //     int curr = q1.front(); 
        //     cout<<curr<<endl;
        //     q1.pop(); 
        //     n1--;
        //     for (auto next : adj1[curr])
        //         if (--indegree1[next] == 0) 
        //             q1.push(next);
        // }
        // return n == 0 && n1 == 0;
        if (edges.size() != n - 1) 
            return false;
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto p : edges) {
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        int cnt = 0;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop(); 
            cnt++;
            for (auto next : adj[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                } else if (next == curr) {
                    return false;
                }
            }
        }
        return cnt == n;
    }
};
