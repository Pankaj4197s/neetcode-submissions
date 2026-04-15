class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0; // Invalid input if it starts with '0'
        int n = s.length();
        vector<int> dp(n, 0);
        
        dp[0] = 1; // First character is valid since it's not '0'
        if (n == 1) return dp[0]; // If length is 1, return the result directly
        
        // Initialize dp[1] based on the first two characters
        if (s[1] != '0') dp[1] = dp[0]; // Single-digit decoding
        if ((s[0] == '1') || (s[0] == '2' && s[1] <= '6')) dp[1] += 1; // Two-digit decoding

        // Fill the dp array for the rest of the string
        for (int i = 2; i < n; i++) {
            if (s[i] != '0') dp[i] = dp[i-1]; // Single-digit decoding
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i-2]; // Two-digit decoding
            }
        }
        return dp[n-1];
    }
};
