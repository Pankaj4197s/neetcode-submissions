class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto i : nums2)
            nums1.push_back(i);
        sort(nums1.begin(), nums1.end());
        int k = nums1.size();
        double res = 0;
        if (k%2)
            res = (double)nums1[k/2];
        else
            res = ((double)(nums1[k/2] + nums1[(k/2)-1])) / 2;
        return res;
    }
};
