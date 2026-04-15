class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp1(n, 0);
        dp1[1] = nums[0];
        vector<int> nums1;
        for(int i=1;i<n;i++)
            nums1.push_back(nums[i]);
        vector<int> dp2(n, 0);
        dp2[1] = nums1[0];
        for(int i=2;i<n;i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i-1]);
        }
        for(int i=2;i<n;i++) {
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums1[i-1]);
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};
