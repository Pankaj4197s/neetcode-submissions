class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasTotal = 0;
        int costTotal = 0;
        for(int i=0;i<n;i++) {
            gasTotal += gas[i];
            costTotal += cost[i];
        }
        if (gasTotal < costTotal)
            return -1;
        vector<int> delta;
        int firstIndex = 0;
        int cnt = 0;
        int del = 0;
        for(int i=0;i<n;i++) {
            del += gas[i] - cost[i];
            if (del < 0) {
                del = 0;
                firstIndex = i+1;
            }
            delta.push_back(del);
            // if (del >= 0) {
            //     cnt++;
            //     if (cnt == 1)
            //         firstIndex = i;
            // }
        }
        // return delta[n-1] >= 0 ? firstIndex : -1;
        return firstIndex;
    }
};
