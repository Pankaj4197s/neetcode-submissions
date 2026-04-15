class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 1)
            return 1;
        int n = s.length();
        int res = 0;
        int reslen = 0;
        for(int i=0;i<n;i++) {
            string tmp = s.substr(i,1);
            res++;
            // Odd Length
            int j = i-1;
            int k = i+1;
            while(j>=0 && k < n) {
                if (s[j] == s[k]) {
                    res++;
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
                    res++;
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
