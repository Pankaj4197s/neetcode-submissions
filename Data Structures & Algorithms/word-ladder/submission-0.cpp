class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        for(auto w : wordList) {
            if (w == endWord) {
                found = true;
                break;
            }
        }   
        if (!found)
            return 0;
        wordList.push_back(beginWord);
        wordList.push_back(endWord);
        unordered_map<string, set<string>> adj;
        for(auto w : wordList) {
            for(auto v : wordList) {
                if (v != w && isEdge(w, v)) {
                    if(adj.find(v) == adj.end())
                        adj[v] = {};
                    if(adj.find(w) == adj.end())
                        adj[w] = {};
                    adj[v].insert(w);
                    adj[w].insert(v);
                }
            }
        }
        // for(auto m : adj) {
        //     cout<<m.first<<endl;
        //     for(auto v : m.second) {
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
        unordered_map<string, int> dist;
        unordered_map<string, bool> visited;

        for(auto w : wordList) {
            dist[w] = INT_MAX;
            visited[w] = false;
        }

        pq.push({beginWord, 0});
        dist[beginWord] = 0;

        while(!pq.empty()) {
            pair<string, int> top = pq.top();
            pq.pop();

            string currWord = top.first;
            int currDist = top.second;

            if (visited[currWord])
                continue;

            visited[currWord] = true;

            // cout<<currWord<<" "<<currDist<<endl;

            for(auto v : adj[currWord]) {
                // cout<<v<<endl;
                if (currDist + 1 < dist[v]) {
                    dist[v] = currDist + 1;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist[endWord] == INT_MAX ? 0 : dist[endWord] + 1;
    }

    bool isEdge(string a, string b) {
        if (a.size() != b.size())
            return false;
        int diff = 0;
        for(int i=0;i<a.size();i++) {
            if (a[i] != b[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }
};
