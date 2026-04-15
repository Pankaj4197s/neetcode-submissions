class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {
                if (stk.size() == 0)
                    return false;
                if (c == ')') {
                    char top = stk.top();
                    stk.pop();
                    if (top != '(')
                        return false;
                } else if (c == ']') {
                    char top = stk.top();
                    stk.pop();
                    if (top != '[')
                        return false;
                } else {
                    char top = stk.top();
                    stk.pop();
                    if (top != '{')
                        return false;
                }
            }
        }
        return stk.size() == 0;
    }
};
