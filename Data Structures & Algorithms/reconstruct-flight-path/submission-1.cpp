class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, map<string, int>> adj;
        for(auto ticket : tickets) {
            adj[ticket[0]][ticket[1]]++;
        }

        // stack<string> q;
        // q.push("JFK");
        vector<string> order;
        // while(!q.empty()) {
        //     string curr = q.top();
        //     cout<<curr<<endl;
        //     q.pop();
        //     order.push_back(curr);
        //     for(auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
        //         cout<<it->first<<" "<<it->second<<endl;
        //         if (it->second > 0) {
        //             it->second--;
        //             q.push(it->first);
        //         }
        //     }
        // }
        dfs("JFK", adj, order);
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(string source, map<string, map<string, int>>& adj, vector<string>& order) {
        for(auto&n : adj[source]) {
            if (n.second > 0) {
                n.second--;
                dfs(n.first, adj, order);
            }
        }
        order.push_back(source);
    }
};
