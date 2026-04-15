class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = nums[0];
        vector<int> right(n);
        right[n-1] = nums[n-1];
        for(int i=1;i<n;i++) {
            left[i] = nums[i]*left[i-1];
        }
        for(int i=n-2; i >= 0;i--) {
            cout<<nums[i]*right[i+1]<<endl;
            right[i] = nums[i]*right[i+1];
        }
        for(auto i:right)
            cout<<i<<endl;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int prod = 1;
            if (i == 0)
                prod = right[i+1];
            else if (i == n-1)
                prod = left[n-2];
            else
                prod = left[i-1]*right[i+1];
            ans.push_back(prod);
        }
        return ans;
    }
};