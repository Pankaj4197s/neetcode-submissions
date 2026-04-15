class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for(auto i : digits)
            num = num*10 + i;
        vector<int> ans;
        num++;
        while (num) {
            ans.push_back(num%10);
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
