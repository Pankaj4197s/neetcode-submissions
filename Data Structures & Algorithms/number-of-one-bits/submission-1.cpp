class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 0;
        int ans = 0;
        while(n) {
            bit = n & 1;
            if (bit)
                ans++;
            n >>= 1;
        }
        return ans;
    }
};
