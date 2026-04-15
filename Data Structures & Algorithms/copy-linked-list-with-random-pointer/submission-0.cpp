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
        // If nullptr, return nullptr
        if (!head)
            return nullptr;

        // Map to store mapping of old -> new Nodes
        unordered_map<Node*, Node*> mp;
        
        // Temp node to traverse
        Node* temp = head;

        // Traverse and add to map
        while(temp) {
            Node* curr = new Node(temp->val);
            mp[temp] = curr;
            temp = temp->next;
        }

        // traverse again and assign next and random pointers
        temp = head;
        
        while(temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        // Return new head
        return mp[head];

    }
};
