class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        int ans = 0;
        for(int i=1;i<n;i++) {
            if (prevEnd > intervals[i][0]) {
                prevEnd = min(prevEnd, intervals[i][1]);
                ans++;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};
