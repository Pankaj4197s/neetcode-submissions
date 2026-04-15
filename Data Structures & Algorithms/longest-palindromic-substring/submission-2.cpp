class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
            return s;
        int n = s.length();
        string res = "";
        int reslen = 0;
        for(int i=0;i<n;i++) {
            string tmp = s.substr(i,1);
            if (tmp.length() > reslen) {
                reslen = tmp.length();
                res = tmp;
            }
            // Odd Length
            int j = i-1;
            int k = i+1;
            while(j>=0 && k < n) {
                if (s[j] == s[k]) {
                    int len = k - j + 1;
                    if (len > reslen) {
                        reslen = len;
                        res = s.substr(j, len);
                    }
                    j--;
                    k++;

                } else {
                    break;
                }
            }

            // Even Length
            j = i;
            k = i+1;
            while(j>=0 && k < n) {
                if (s[j] == s[k]) {
                    int len = k - j + 1;
                    if (len > reslen) {
                        reslen = len;
                        res = s.substr(j, len);
                    }
                    j--;
                    k++;

                } else {
                    break;
                }
            }
        }
        return res;
    }
};
