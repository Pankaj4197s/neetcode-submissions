class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        map<char, string> comb;
        comb['2'] = "abc";
        comb['3'] = "def";
        comb['4'] = "ghi";
        comb['5'] = "jkl";
        comb['6'] = "mno";
        comb['7'] = "pqrs";
        comb['8'] = "tuv";
        comb['9'] = "wxyz";
        set<string> res;
        res.insert("");
        for(auto c : digits) {
            set<string> temp;
            for(auto r : res) {
                for(auto l : comb[c])
                    temp.insert(r + l);
            }
            res = temp;
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};