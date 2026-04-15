class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> cnt;
        for(auto n : nums) {
            if (cnt.find(n) != cnt.end())
                return n;
            cnt.insert(n);
        }
        return -1;
    }
};
