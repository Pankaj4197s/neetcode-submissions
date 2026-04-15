class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> resL;
        vector<vector<int>> resR;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 1)
            return intervals;
        int newStart = 0;
        int newEnd = 0;
        for(int i=0;i<n-1;i++) {
            newStart = intervals[i+1][0];
            newEnd = intervals[i+1][1];
            cout<<newStart<<" "<<newEnd<<endl;
            if (intervals[i][1] < newStart) {
                resL.push_back(intervals[i]);
                cout<<"L: "<<resL.size()<<endl;
            }
            else if (newEnd < intervals[i][0]) {
                resR.push_back(intervals[i]);
                cout<<"R: "<<resR.size()<<endl;
            }
            else {
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
                cout<<"11 "<<newStart<<" "<<newEnd<<endl;
                intervals[i+1] = {newStart, newEnd};
            }
        }
        resL.push_back({newStart, newEnd});
        cout<<resL.size()<<endl;
        for(auto i : resR)
            resL.push_back(i);
        cout<<resL.size()<<endl;
        return resL;
    }
};