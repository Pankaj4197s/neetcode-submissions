class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i < n;i++) {
            int count = 0;
            int j = i;
            cout<<i<<endl;
            int gasLeft = gas[j] - cost[j];
            while(gasLeft >= 0) {    // Can go to next stop
                cout<<j<<" "<<gasLeft<<endl;
                count++;
                if (count == n)
                    return i;
                else {
                    j = (j+1)%n;
                    gasLeft += gas[j] - cost[j];
                }
            }
        }
        return -1;
    }
};
