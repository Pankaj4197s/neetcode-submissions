class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, l = 0, r = 0;
        while(r < prices.size()) {
            if (prices[l] > prices[r])
                l = r;
            else
                ans = max(ans, prices[r] - prices[l]);
            r++;
        }
        return ans;
    }
};

