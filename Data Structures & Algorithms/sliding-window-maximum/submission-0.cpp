class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<=n-k;i++) {
            int mx = nums[i];
            for(int j=i;j<i+k;j++)
                mx = max(mx, nums[j]);
            ans.push_back(mx);
        }
        return ans;
    }
};
