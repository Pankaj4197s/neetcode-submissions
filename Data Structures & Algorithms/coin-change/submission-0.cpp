class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, 100000);
    dp[0] = 0;
    for(int i=1;i<=amount;i++) {
        for(auto coin : coins) {
            if (i - coin >= 0) {
                int change = 1 + dp[i-coin];
                dp[i] = min(dp[i], change);
            }
        }
    }
    if (dp[amount] == 100000)
        return -1;
    return dp[amount];
    }
};
