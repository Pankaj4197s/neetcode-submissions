class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int max_len=0;
        unordered_set<char> unique;
        for(int r=0;r<s.length();r++) {
            while(unique.find(s[r]) != unique.end()) {
                unique.erase(s[l]);
                l++;
            }
            unique.insert(s[r]);
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};
