class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0, star = 0;
        for(auto c : s) {
            if (c == '(')
                open++;
            else if (c == ')')
                close++;
            else
                star++;
            if (close > open + star)
                return false;
        }
        open = 0, close = 0, star = 0;
        for(int i = s.size()-1;i >= 0;i--) {
            char c = s[i];
            if (c == '(')
                open++;
            else if (c == ')')
                close++;
            else
                star++;
            if (open > close + star)
                return false;
        }
        return true;
    }
};