class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char, set<char>> adj;
        map<char, int> inDegree;
        set<char> unique;
        for(auto w : words) {
            for(auto c : w) {
                unique.insert(c);
                inDegree[c] = 0;
            }
        }
        int n = words.size();
        for(int i=0;i<n-1;i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            if (w2.size() < w1.size() && w1.substr(0, w2.size()) == w2)
                return "";
            int k = 0, l = 0;
            while(k < w1.size() && l < w2.size()) {
                if (w1[k] == w2[l]) {
                    k++;
                    l++;
                } else {
                    break;
                }
            }
            if (k < w1.size() && l < w2.size()) {
                adj[w1[k]].insert(w2[l]);
            }
        }
        for(auto a : adj)
            for(auto c : a.second)
                inDegree[c]++;
        string order;
        queue<char> q;
        for(auto c : unique) {
            if (inDegree[c] == 0) {
                q.push(c);
            }
        }
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            order += c;
            for(auto n : adj[c]) {
                if (--inDegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        return order.size() == unique.size() ? order : "";
    }
};