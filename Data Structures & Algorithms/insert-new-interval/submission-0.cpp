class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resL;
        vector<vector<int>> resR;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        for(int i=0;i<n;i++) {
            if (intervals[i][1] < newStart)
                resL.push_back(intervals[i]);
            else if (newEnd < intervals[i][0])
                resR.push_back(intervals[i]);
            else {
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
            }
        }
        resL.push_back({newStart, newEnd});
        for(auto i : resR)
            resL.push_back(i);
        return resL;
    }
};
