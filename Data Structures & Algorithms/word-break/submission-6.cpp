class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;  // Base case: an empty string can always be segmented.

        for (int i = 0; i <= s.size(); i++) {
            if (dp[i]) {  // Only proceed if the prefix up to `i` can be segmented.
                for (const auto& w : wordDict) {
                    if ((i + w.size()) <= s.size() && s.substr(i, w.size()) == w) {
                        dp[i + w.size()] = true;  // Mark this position as reachable.
                    }
                    // if (dp[i + w.size()])
                    //     break;
                }
            }
        }

        return dp[s.size()];
    }
};
