class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int n = nums.size();
        int h = n-1;
        int res = nums[0];
        while(l <= h) {
            if (nums[l] < nums[h]) {
                res = min(res, nums[l]);
                break;
            }
            int mid = (l+h)/2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return res;
    }
};
