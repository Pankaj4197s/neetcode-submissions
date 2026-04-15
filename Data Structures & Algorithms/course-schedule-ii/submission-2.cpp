class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> ord;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ord.push_back(i);
            }
        }    
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop(); 
            numCourses--;
            for (auto next : adj[curr])
                if (--indegree[next] == 0) {
                    q.push(next);
                    ord.push_back(next);
                }
        }
        vector<int> res;
        return numCourses == 0 ? ord : res;
    }
};