class LRUCache {
public:
    int cap;
    int op;
    unordered_map<int, int> mp; // key/value
    unordered_map<int, int> key_op; // key/op
    map<int, int> op_key;   //  op/key
    LRUCache(int capacity) {
        cap = capacity;
        op = 0;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        int prev_op = key_op[key];
        key_op[key] = ++op;
        op_key.erase(prev_op);
        op_key[op] = key;
        
        // cout<<"Get call for key: "<<key<<endl;
        // for (auto &p : mp) {
        //     cout << "(" << p.first << ", " << p.second << ") ";
        // }
        // cout<<endl;
        // return mp.find(key) != mp.end() ? mp[key] : -1;  // Why is it returning 0 for removed keys?
        return mp.at(key);
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            // Evacuate Least recently used key
            cout<<"Put call"<<endl;
            cout<<key<<" "<<value<<endl;
            
            // mp.erase(prev_key);  // Why is this not deleting prev_key from map?
            // Confirm erasure
            if (mp.size() == cap) {
                // if (mp.erase(prev_key)) {
                //     cout << "Successfully erased key: " << prev_key << endl;
                // } else {
                //     cout << "Failed to erase key: " << prev_key << endl;
                // }
                auto it = op_key.begin();
                pair<int, int> fe = *it;
                int prev_key = fe.second;
                int prev_op = fe.first;
                cout<<prev_key<<" "<<prev_op<<endl;
                cout<<"Value to be deleted is: "<<mp[prev_key]<<" "<<key_op[prev_key]<<endl;
                mp.erase(prev_key);
                key_op.erase(prev_key);
                op_key.erase(it);
            } 
        } else {
            // Existing key case: just remove the old operation record
            int prev_op = key_op[key];
            op_key.erase(prev_op);
        }
        mp[key] = value;
        key_op[key] = ++op;
        op_key[op] = key;
        for (auto &p : mp) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout<<endl;
    }
};
