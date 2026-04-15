class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for(int i=0; i<temperatures.size();i++) {
            int ans = 0;
            bool found = false;
            for(int j=i+1;j<temperatures.size();j++) {
                ans++;
                if (temperatures[j] > temperatures[i]) {
                    found = true;
                    break;
                }
            }
            if (found)
                res.push_back(ans);
            else
                res.push_back(0);
        }
        return res;
    }
};
