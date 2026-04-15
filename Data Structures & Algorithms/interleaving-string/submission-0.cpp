class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3, 0, 0, 0);
    }
    
    bool dfs(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (k == s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
        
        if (i < s1.length() && s1[i] == s3[k]) {
            if (dfs(s1, s2, s3, i + 1, j, k + 1)) {
                return true;
            }
        }
        
        if (j < s2.length() && s2[j] == s3[k]) {
            if (dfs(s1, s2, s3, i, j + 1, k + 1)) {
                return true;
            }
        }
        
        return false;
    }
};