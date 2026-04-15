/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;
        Node* temp = head;

        while(temp) {
            if (mp.find(temp) == mp.end())
                mp[temp] = new Node(0);
            mp[temp]->val = temp->val;
            if (mp.find(temp->next) == mp.end())
                mp[temp->next] = new Node(0);
            mp[temp]->next = mp[temp->next];
            if (mp.find(temp->random) == mp.end())
                mp[temp->random] = new Node(0);
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        // Return new head
        return mp[head];
    }
};
