class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n&1);
            n >>= 1;
        }
        int size = digits.size();
        cout<<size<<endl;
        // for(int i = 1; i <= 32 - digits.size();i++) {
// fails as digits.size() is dynamic. If it is part of calculation, remove it.
        // }
        for(int i = 1; i <= 32 - size;i++)
            digits.push_back(0);
        cout<<digits.size()<<endl;
        uint32_t rev = 0;
        int  pw = 31;
        for(auto i : digits)
            rev += i*pow(2,pw--);
        return rev;
        
    }
};
