class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> chosen(nums.size(), false);
        dfs(res, perm, nums, chosen);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& perm, vector<int>& nums, vector<bool>& chosen) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for(int i = 0;i<nums.size();i++) {
            if (chosen[i] == false) {
                chosen[i] = true;
                perm.push_back(nums[i]);
                dfs(res, perm, nums, chosen);
                perm.pop_back();
                chosen[i] = false;
            }
        }
    }
};
