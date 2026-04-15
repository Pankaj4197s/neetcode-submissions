class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> cs;
        unordered_map<char, int> ct;
        for(auto c : s)
            cs[c]++;
        for(auto c : t)
            ct[c]++;
        for(auto c : cs) {
            if (c.second != ct[c.first])
                return false;
        }
        return true;
    }
};
