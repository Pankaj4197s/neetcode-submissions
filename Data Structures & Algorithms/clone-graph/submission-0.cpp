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
        stack<Node*> s;
        s.push(node);
        unordered_set<int> visited;
        unordered_map<Node*, Node*> mp;
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            if (visited.find(temp->val) == visited.end()) {
                visited.insert(temp->val);
                for(auto n : temp->neighbors)
                    s.push(n);
                Node* copy = new Node(temp->val);
                mp[temp] = copy;
            }
        }
        // DFS 2
        unordered_set<int> visited2;
        s.push(node);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            if (visited2.find(temp->val) == visited2.end()) {
                visited2.insert(temp->val);
                Node* copy = mp[temp];
                for(auto n : temp->neighbors) {
                    copy->neighbors.push_back(mp[n]);
                    s.push(n);
                }
            }
        }
        return mp[node];
    }
};
