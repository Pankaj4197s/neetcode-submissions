class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        sort(intervals.begin(), intervals.end());
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        map<int, int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int i=0;
        for(auto q : sortedQueries) {
            while(i < n && intervals[i][0] <= q) {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q){
                minHeap.pop();
            }
            res[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }
        vector<int> ans;
        for(auto q : queries)
            ans.push_back(res[q]);
        return ans;
    }
};
