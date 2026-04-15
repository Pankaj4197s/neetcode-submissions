class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // dp[i][j] -> max value that can be gathered by bursting balloons i...j
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<int> newNums(n + 2, 1);
        vector<vector<int>> dp(n+2, vector<int>(n + 2, -1));
        return dfs(nums, 1, nums.size() - 2, dp);
    }

    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = 0;
        for(int i=l;i<=r;i++) {
            int coins = nums[l-1]*nums[i]*nums[r+1];
            coins += dfs(nums, l, i-1, dp) + dfs(nums, i+1, r, dp);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }
};