class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)  
            sum += i;   
        if (sum%2)
            return false;
        int n = nums.size();
        int m = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        for(int i=1;i<=n;i++)
            dp[i][0] = true;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = dp[i-1][j] || (j >= nums[i-1] && dp[i-1][j - nums[i-1]]);
            }
        }
        return dp[n][m];
    }
};
