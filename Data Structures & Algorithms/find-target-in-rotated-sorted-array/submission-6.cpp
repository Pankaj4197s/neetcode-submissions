class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h) {
            int mid = (l+h)/2;
            cout<<l<<" "<<mid<<" "<<h<<endl;
            if (nums[mid] == target)
                return mid;
            cout<<nums[mid]<<endl;
            cout<<nums[l]<<endl;
            if (target < nums[l])
                l++;
            else if (target > nums[h])
                h--;
            else {
                if (nums[mid] < target)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return idx;
    }
};
