class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr = 0;
        int ways = 0;
        dfs(nums, 0, curr, ways, target);
        return ways;
    }

    void dfs(vector<int>& nums, int i, int curr, int& ways, int target) {
        if (i >= nums.size()) {
            if (curr == target)
                ways++;
            return;
        }
        dfs(nums, i+1, curr + nums[i], ways, target);
        dfs(nums, i+1, curr - nums[i], ways, target);
    }
};
