class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = 0; i < temperatures.size();i++) {
            while(!stk.empty() && stk.top().first < temperatures[i]) {
                ans[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};