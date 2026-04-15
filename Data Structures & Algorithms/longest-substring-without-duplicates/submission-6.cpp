class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // if (n <= 1)
        //     return n;
        // set<char> seen;
        // int i=0;
        // int j=1;
        // int ans = 0;
        // while(i < n-1) {
        //     int j = i+1;
        //     seen.insert(s[i]);
        //     // Increase j
        //     while(j < n && seen.find(s[j]) == seen.end()) {
        //         seen.insert(s[j++]);
        //     }
        //     ans = max(ans, j - i);
        //     // Move window to validity
        //     while(i < j && seen.find(s[j]) != seen.end()) {
        //         seen.erase(s[i++]);
        //     }
        // }
        // return ans;
        unordered_set<char> seen;
    int i = 0, j = 0, ans = 0;

    while (j < n) {
        // Expand the window by moving `j`
        if (seen.find(s[j]) == seen.end()) {
            seen.insert(s[j]);
            ans = std::max(ans, j - i + 1);
            ++j;
        } else {
            // Shrink the window by moving `i`
            seen.erase(s[i]);
            ++i;
        }
    }

    return ans;
        // unordered_map<char, int> lastSeen;
        // int n = s.length();
        // int ans = 0;
        // int i=0;
        // int j=1;
        // while(i < n-1) {
        //     lastSeen[s[i]] = i;
        //     //     // Increase j
        //     while(j < n && lastSeen.find(s[j]) == lastSeen.end()) {
        //         lastSeen[s[j]] = j;
        //         j++;
        //     }
        //     ans = max(ans, j - i);
        //     i = lastSeen[s[j]];
        //     lastSeen[s[j]] = j;
        //     // // Move window to validity
        //     // while(i < j && seen.find(s[j]) != seen.end()) {
        //     //     seen.erase(s[i++]);
        //     // }
        // }
    }
};
