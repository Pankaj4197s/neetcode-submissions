class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<int> ans;
        for(auto q : queries) {
            int res = INT_MAX;
            for(auto i : intervals) {
                if (i[0] <= q && q <= i[1])
                    res = min(res, i[1] - i[0] + 1);
            }
            if (res == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(res);
        }
        return ans;
    }
};
