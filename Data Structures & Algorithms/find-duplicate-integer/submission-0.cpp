class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto n : nums)
            cnt[n]++;
        for(auto c : cnt)
            if (c.second > 1)
                return c.first;
        return -1;
    }
};
