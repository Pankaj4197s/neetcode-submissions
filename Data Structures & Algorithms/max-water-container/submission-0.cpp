class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1;
        for(int i=0;i<heights.size() - 1;i++) {
            for(int j=i+1; j<heights.size();j++) {
                int w = j - i;
                int h = min(heights[i], heights[j]);
                int vol = h*w;
                ans = max(ans, vol);
            }
        }
        return ans;
    }
};
