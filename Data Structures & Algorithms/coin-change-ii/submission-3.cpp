class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size() + 1, 
                            vector<int>(amount + 1, -1));
        return dfs(amount, coins, 0, 0, memo);
    }

    int dfs(int amount, vector<int>& coins, int sum, int i, vector<vector<int>>& memo) {
        if (i >= coins.size()) 
            return 0;
        if (sum > amount)
            return 0;
        if (sum == amount)
            return 1;
        if (memo[i][sum] != -1)
            return memo[i][sum];
        int ways = 0;
        ways += dfs(amount, coins, sum + coins[i], i, memo);
        ways += dfs(amount, coins, sum, i+1, memo);
        memo[i][sum] = ways;
        return ways;
    }
};
