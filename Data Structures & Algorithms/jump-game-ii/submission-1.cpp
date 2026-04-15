class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 100000);
        dp[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            int maxJump = nums[i];
            for(int j=maxJump;j>0;j--) {
                if (j < nums.size() && dp[i+j] != -1) {
                    dp[i] = min(1 + dp[i+j], dp[i]);
                    // break;
                }
            }
        }
        return dp[0];
        // int target = nums.size() - 1;
        // int ans = 0;
        // for(int i = nums.size() - 2; i>=0; i--) {
        //     if (i + nums[i] >= target) {
        //         target = i;
        //         ans++;
        //     }
        // }
        // return ans;
    }
};
