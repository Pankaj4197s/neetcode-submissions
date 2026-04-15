class Solution {
public:
    int reverse(int x) {
        int temp = x;
        // int temp = abs(x);
        vector<int> digits;
        while(temp) {
            digits.push_back(temp%10);
            temp /= 10;
        }
        int res = 0;
        for(auto d : digits) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > INT_MAX % 10))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && d < INT_MIN % 10))
                return 0;
            res = res*10 + d;
        }
        return res;
    }
};
