class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        int l = 0, r = 0;
        unordered_map<char, int> cnt;
        int mx = 0;
        while(l < n && r < n) {
            cnt[s[r]]++;
            mx = max(cnt[s[r]], mx);
            int rep = r-l+1 - mx;
            if (rep <= k)
                ans = max(r-l+1, ans);
            else {
                cnt[s[l]]--;
                // mx = max(cnt[s[l]], mx);
                l++;
            }
            // while (r-l+1 - mx > k) {
            //     cnt[s[l]]--;
            //     l++;
            // }
            ans = max(r-l+1, ans);
            r++;
        }
        return ans;
    }
};
