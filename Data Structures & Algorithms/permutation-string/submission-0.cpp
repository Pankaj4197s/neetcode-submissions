class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        vector<int> s1C(26, 0);
        for(auto c : s1)
            s1C[c - 'a']++;
        int n = s1.length();
        int m = s2.length();
        for(int i=0;i<=m-n;i++) {
            vector<int> s2C(26, 0);
            for(int j=i;j<i+n;j++) {
                cout<<s2[j]<<endl;
                s2C[s2[j] - 'a']++;
            }
            bool match = true;
            for(int k=0;k<26;k++) {
                if(s1C[k] != 0 && s1C[k] != s2C[k]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }
        return false;
    }
};
