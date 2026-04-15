class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> count;
        for(auto i : nums) {
            if (count.find(i) != count.end())
                return true;
            count.insert(i);
        }
        return false;
    }
};