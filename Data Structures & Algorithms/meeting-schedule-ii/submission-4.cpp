/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) -> bool {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        vector<int> endTimes;
        endTimes.push_back(intervals[0].end);
        for(int i=1;i<n;i++) {
            vector<int> temp = endTimes;
            bool found = false;
            for (auto end : temp) {
                if (end <= intervals[i].start) {
                    end = intervals[i].end;
                    found = true;
                    break;
                }
            }
            if (!found)
                endTimes.push_back(intervals[i].end);
        }
        return endTimes.size();
    }
};
