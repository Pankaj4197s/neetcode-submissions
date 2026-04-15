class LRUCache {
public:
    int cap;
    int op;
    unordered_map<int, int> mp; // key/value
    unordered_map<int, int> key_op; // key/op
    map<int, int> op_key;   // op/key

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

        return mp.at(key);  // Use `at()` to avoid accidental insertion
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {  // New key case
            if (mp.size() == cap) {
                // Evacuate the least recently used key
                auto it = op_key.begin();
                int prev_key = it->second;
                cout << "Evicting key: " << prev_key << ", Value: " << mp[prev_key] << endl;
                mp.erase(prev_key);
                key_op.erase(prev_key);
                op_key.erase(it);
            }
        } else {
            // Existing key case: just remove the old operation record
            int prev_op = key_op[key];
            op_key.erase(prev_op);
        }

        // Update key with new value and operation
        mp[key] = value;
        key_op[key] = ++op;
        op_key[op] = key;

        // Debug print
        for (auto &p : mp) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
};
