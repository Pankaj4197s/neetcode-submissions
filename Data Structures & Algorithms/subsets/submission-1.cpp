class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        res.insert({});
        for(auto n : nums) {
            set<vector<int>> temp = res;
            set<vector<int>> nTemp;
            nTemp.insert({n});
            for(auto set : temp) {
                set.push_back(n);
                nTemp.insert(set);
            }
            for(auto ns : nTemp)
                res.insert(ns);
        }
        vector<vector<int>> ans;
        for(auto s : res)
            ans.push_back(s);
        ans.push_back({});
        return ans;
    }
};
