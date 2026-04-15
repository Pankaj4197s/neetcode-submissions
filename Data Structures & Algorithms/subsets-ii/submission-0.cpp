class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subset;
        dfs(res, subset, nums, 0);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }

    void dfs(set<vector<int>>& res, vector<int>& subset, vector<int>& nums, int i) {
        if (i == nums.size()) {
            vector<int> temp = subset;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        subset.push_back(nums[i]);
        dfs(res, subset, nums, i+1);
        subset.pop_back();
        dfs(res, subset, nums, i+1);
    }
};
