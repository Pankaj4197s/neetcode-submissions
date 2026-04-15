class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            int prod = nums[i];
            ans = max(ans, prod);
            for(int j=i+1;j<nums.size();j++) {
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};
