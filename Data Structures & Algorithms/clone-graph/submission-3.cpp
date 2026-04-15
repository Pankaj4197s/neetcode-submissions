/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(auto n : curr->neighbors) {
                if (mp.count(n) == 0) {
                    mp[n] = new Node(n->val);
                    q.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
        }
        return mp[node];
    }
};
