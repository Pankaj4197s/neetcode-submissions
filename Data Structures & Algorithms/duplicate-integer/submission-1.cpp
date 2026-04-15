class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto i : nums) {
            if (count.find(i) != count.end())
                return true;
            count[i] = 1;
        }
        return false;
    }
};