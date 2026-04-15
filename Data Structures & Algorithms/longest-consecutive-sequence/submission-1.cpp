class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1); // Longest sequence ending in that index. Each number is sequence of length 1
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if (nums[j] + 1 == nums[i])
                    dp[i] = 1 + dp[j];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
