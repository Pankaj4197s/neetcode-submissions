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
        vector<int> startTimes;
        vector<int> endTimes;
        for(auto i : intervals) {
            startTimes.push_back(i.start);
            endTimes.push_back(i.end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        int count = 0, res = 0;
        int s = 0, e = 0;
        while(s < n) {
            if (startTimes[s] < endTimes[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
