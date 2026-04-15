class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(nums, target, 0, comb, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int target, int i, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        if (target < 0 || i == nums.size())
            return;
        comb.push_back(nums[i]);
        dfs(nums, target - nums[i], i, comb, res);
        comb.pop_back();
        dfs(nums, target, i+1, comb, res);
    }
};
