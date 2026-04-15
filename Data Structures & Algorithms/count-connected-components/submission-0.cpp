class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int cc = 0;
        for(int i=0;i<n;i++)
            if (!visited[i]) {
                cc++;
                dfs(adj, visited, i, n);
            }
        return cc;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int i,int n) {
        if (visited[i])
            return;
        visited[i] = true;
        for(auto j : adj[i])
            dfs(adj, visited, j, n);
    }
};
