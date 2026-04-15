class Solution {
public:
    map<int, bool> processed;
    bool isHappy(int n) {
        if (!processed[n]) {
            int num = getSquaredSum(n);
            cout<<num<<endl;
            processed[n] = true;
            if (num == 1) {
                return true;
            } else {
                return isHappy(num);
            }
        }
        return false;
    }

    int getSquaredSum(int n) {
        int ans = 0;
        while (n > 0) {
            int res = n%10;
            ans += res*res;
            n /= 10;
        }
        return ans;
    }
};
