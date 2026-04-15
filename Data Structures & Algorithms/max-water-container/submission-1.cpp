class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1;
        int sz = heights.size();
        int l = 0;
        int r = sz - 1;
        while(l < r) {
            int w = r - l;
            int h = min(heights[l], heights[r]);
            int vol = h*w;
            ans = max(ans, vol);
            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
