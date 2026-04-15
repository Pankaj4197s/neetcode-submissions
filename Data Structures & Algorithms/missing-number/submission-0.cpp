class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);
        for(auto i : nums)
            freq[i] = 1;
        for(int i = 0; i <= n; i++) {
            if(!freq[i])
                return i;
        }
        return -1;
    }
};
