class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = -1;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            ans = max(ans, heights[i]);
            int l = i;
            int r = i;
            while(l >= 0 && heights[l] >= heights[i])
                l--;
            while(r < n && heights[r] >= heights[i])
                r++;
            // if (l < 0)
            //     l = 0;
            // if (r == n)
            //     r = n-1;
            ans = max(ans, (r - l - 1)*heights[i]);
        }
        return ans;
    }
};
