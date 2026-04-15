class Solution {
public:
//     vector<vector<int>> combinationSum(vector<int>& nums, int target) {
//         vector<vector<int>> res;
//         vector<int> comb;
//         dfs(nums, target, 0, comb, res);
//         return res;
//     }

// private:
//     void dfs(vector<int>& nums, int target, int i, vector<int>& comb, vector<vector<int>>& res) {
//         if (i == nums.size())
//             return;
//         if (target <= 0) {
//             res.push_back(comb);
//             return;
//         }
//         comb.push_back(nums[i]);
//         dfs(nums, target - nums[i], i, comb, res);
//         dfs(nums, target - nums[i], i+1, comb, res);
//         comb.pop_back();
//         dfs(nums, target, i+1, comb, res);
//     }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) { 
        set<vector<int>> res;
        vector<int> comb;
        dfs(target, res, comb, nums);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }

    void dfs(int target, set<vector<int>>& res, vector<int>& comb, vector<int>& nums) {
        if (target == 0) {
            vector<int> temp = comb;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (target < 0)
            return;
        for(int i=0;i<nums.size();i++) {
            cout<<"Target: "<<target<<endl;
            cout<<"Curr: "<<nums[i]<<endl;
            cout<<target-nums[i]<<endl;
            if (target - nums[i] >= 0) {
                comb.push_back(nums[i]);
                dfs(target-nums[i], res, comb, nums);
                comb.pop_back();
            }
        //     comb.pop_back();
        }
    }
};
