class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hm;
        for(auto i : nums) {
            hm.insert(i);
        }
        for(auto i : nums) {
            int next = i+1;
            int curr = 1;
            if (hm.find(i-1) == hm.end()) {
                while(hm.find(next) != hm.end()) {
                    next++;
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};