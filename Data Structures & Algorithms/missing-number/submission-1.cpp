class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumE = (n*(n+1)) / 2;
        int sum = 0;
        for(auto i : nums)
            sum += i;
        return sumE - sum;
    }
};
