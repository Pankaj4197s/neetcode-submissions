class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        vector<int> start, end;
        for(auto& i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0, e = 0, count = 0;
        int n = intervals.size();
        int ans = 0;
        while (s < n) {
            if (start[s] < end[e]) {
                count++;
                s++;
                ans = max(ans, count);
            } else {
                count--;
                e++;
            }
        }
        return ans;
    }
};