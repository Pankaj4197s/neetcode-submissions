class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stn;
        for(auto i : stones)
            stn.push(i);
        // Start simulation
        while(stn.size() > 1) {
            int x = stn.top();stn.pop();
            int y = stn.top();stn.pop();
            if (x != y) {
                stn.push(x - y);
            }
        }
        return stn.size() == 1 ? stn.top() : 0;
    }
};
