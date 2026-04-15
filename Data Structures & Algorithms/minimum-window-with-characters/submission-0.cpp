class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cntT,window;
        int n = s.size();
        for(auto c: t)
            cntT[c]++;
        int l=0;
        int have = 0;
        int need = cntT.size();
        int ans = INT_MAX;
        // while(l < n && r < n && l <= r) {
        //     if (cntT.find(s[l]) == cntT.end())  //  can't start from this index;
        //         l++;
        //     if (cntT.find(s[r]) == cntT.end())  //  can't end at this index;
        //         r--;
            
        // }
        int resLen = 0;
        int start = -1;
        for(int r=0;r<n;r++) {
            char c = s[r];
            window[c]++;
            if (cntT.count(c) && window[c] == cntT[c])
                have++;
            while(have == need) {
                if (r-l+1 < ans) {
                    ans = r-l+1;
                    start = l;
                }
                window[s[l]]--;
                if (cntT.count(s[l]) && window[s[l]] < cntT[s[l]])
                    have--;
                l++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};
