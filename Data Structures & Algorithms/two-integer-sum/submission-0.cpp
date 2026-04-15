class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        vector<int> ans;
        for(int i = 0; i < nums.size() ; i++) {
            int complement = target - nums[i];
            if (diff.find(complement) != diff.end()) {
                ans.push_back(i);
                ans.push_back(diff[complement]);
                sort(ans.begin(), ans.end());
                return ans;
            }
            diff[nums[i]] = i;
        }
        return {};
    }
};
