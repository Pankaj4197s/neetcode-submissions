class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            unordered_map<char, int> cnt;
            int mx = 0;
            for(int j=i;j<n;j++) {
                cnt[s[j]]++;
                mx = max(mx, cnt[s[j]]);
                int rep = j-i+1 - mx;
                if (rep <= k)
                    ans = max(ans, j-i+1);
                else {
                    break;
                }
            }
        }
        return ans;
    }
};
