class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        for(int i = nums.size() - 2; i >= 0; i--) {
            int maxJump = nums[i];
            for(int j=1;j<=maxJump;j++) {
                if (dp[i+j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
