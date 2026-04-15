class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(auto t : tasks)
            cnt[t-'A']++;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for(auto c : cnt) 
            if (c > 0)
                pq.push(c);
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                top--;
                if (top > 0) {
                    q.push({top, time + n});
                }
            } else {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
