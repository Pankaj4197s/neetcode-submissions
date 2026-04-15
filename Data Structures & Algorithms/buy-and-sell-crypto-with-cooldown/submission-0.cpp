class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n);
        vector<int> rest(n);
        vector<int> cool(n);
        hold[0] = -1*prices[0];
        rest[0] = 0;
        cool[0] = INT_MIN;
        for(int i=1;i<n;i++) {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            rest[i] = max(rest[i-1], cool[i-1]);
            cool[i] = max(cool[i-1], hold[i-1] + prices[i]);
        }
        return max(rest[n-1], cool[n-1]);
    }
};
