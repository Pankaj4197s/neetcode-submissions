class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> comb;
        dfs(nums, target, 0, comb, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }

private:
    void dfs(vector<int>& nums, int target, int i, vector<int>& comb, set<vector<int>>& res) {
        if (target == 0) {
            vector<int> temp = comb;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (target < 0 || i == nums.size())
            return;
        comb.push_back(nums[i]);
        dfs(nums, target - nums[i], i+1, comb, res);
        comb.pop_back();
        dfs(nums, target, i+1, comb, res);
    }
};
