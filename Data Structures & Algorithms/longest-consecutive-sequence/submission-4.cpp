class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            int curr = 1;
            int j = i;
            while(j < n) {
                if (nums[j] == nums[i])
                    j++;
                else if (nums[j] == nums[i] + 1) {
                    curr++;
                    i = j;
                } else {
                    break;
                }
                cout<<i<<" "<<curr<<endl;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};