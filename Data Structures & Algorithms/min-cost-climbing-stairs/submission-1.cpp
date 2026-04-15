class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        for(int i=2;i<=cost.size();i++) {
            cout<<dp[i-2]+cost[i-2]<<endl;
            cout<<dp[i-1]+cost[i-1]<<endl;
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        }
        return dp[cost.size()];
    }
};
