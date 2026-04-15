class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // vector<int> digits;
        // while(n) {
        //     digits.push_back(n&1);
        //     n >>= 1;
        // }
        // vector<int> fdigits;
        // for(int i = 1; i <= 32 - digits.size();i++)
        //     fdigits.push_back(0);
        // for(auto i : digits)
        //     fdigits.push_back(i);
        // uint32_t rev = 0;
        // cout<<fdigits.size()<<endl;
        // long long pw = 0;
        // for(auto i : fdigits)
        //     rev += i*pow(2,pw++);
        // return rev;
        string digits;
        while(n) {
            digits += n&1 ? '1' : '0';
            n >>= 1;
        }
        cout<<digits<<" "<<digits.length()<<endl;
        int steps = 32 - digits.length();
        while(steps) {
            digits = digits + '0';
            cout<<steps<<" "<<digits<<endl;
            steps--;
        }
        // for(int i = 1; i <= 32 - digits.length();i++) {
        //     digits = '0' + digits;
        //     cout<<i<<" "<<digits<<endl;
        // }
        cout<<digits<<endl;
        // reverse(digits.begin(), digits.end());
        cout<<digits<<endl;
        uint32_t rev = 0;
        int pw = 31;
        for(auto c : digits) {
            uint32_t d = (c == '1') ? 1 : 0;
            rev += d*pow(2,pw--);
        }
        return rev;
    }
};
