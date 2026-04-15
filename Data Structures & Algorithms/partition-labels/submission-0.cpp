class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals;
        for(int i=0;i<26;i++) {
            char c = 'a' + i;
            int start = -1;
            int end = -1;
            for(int j=0;j<s.size();j++) {
                if (s[j] == c) {
                    if (start == -1) {
                        start = j;
                        end = j;
                    } else {
                        end = j;
                    }
                }
            }
            if (start != -1)
                    intervals.push_back({start, end});
        }
        intervals = merge(intervals);
        vector<int> res;
        for(auto i : intervals) {
            res.push_back(i[1] - i[0] + 1);
        }
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
