class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int runningSum = 0;
        int ways = 0;
        dfs(runningSum, nums, 0, target, ways);
        return ways;
    }

    void dfs(int runningSum, vector<int>& nums, int i, int target, int& ways) {
        if (i == nums.size())
            return;
        runningSum += nums[i];
        dfs(runningSum, nums, i+1, target, ways);
        if (i == nums.size() - 1 && target == runningSum)
            ways++;
        runningSum -= 2*nums[i];
        dfs(runningSum, nums, i+1, target, ways);
        if (i == nums.size() - 1 && target == runningSum)
            ways++;
    }

};
