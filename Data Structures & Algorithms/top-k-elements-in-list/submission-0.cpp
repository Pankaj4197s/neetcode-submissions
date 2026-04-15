class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) { 
        return a.first > b.first; 
    }   

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        for(auto i : nums) {
            cnt[i]++;
        }
        vector<pair<int, int>> freqs;
        vector<int> ans;
        for(auto i : cnt) {
            freqs.push_back({i.second, i.first});
        }
        sort(freqs.begin(), freqs.end(), cmp);
        for(auto i : freqs) {
            if (k > 0) {
                ans.push_back(i.second);
                k--;
            } else {
                break;
            }
        }
        return ans;
    }
};
