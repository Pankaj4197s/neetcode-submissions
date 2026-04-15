class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (mp.find(key) == mp.end()) {
            mp[key] = {};
        }
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> ts = mp[key];
        if (ts.size() == 0)
            return "";
        int l = 0;
        int h = ts.size() - 1;
        string ans = "";
        while(l <= h) {
            int mid = (l+h)/2;
            if (ts[mid].first <= timestamp) {
                ans = ts[mid].second;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};
