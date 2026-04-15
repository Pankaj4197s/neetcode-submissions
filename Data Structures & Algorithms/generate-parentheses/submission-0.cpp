class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int len = 0;
        stack<string> pars;
        pars.push("");
        vector<string> temp;
        while(len < 2*n) {
            while(!pars.empty()) {
                string str = pars.top();
                pars.pop();
                if (isValid(str)) {
                    if (isValid(str+"("))
                        temp.push_back(str+"(");
                    if (isValid(str+")"))
                        temp.push_back(str+")");
                }     
            }
            for(auto s : temp)
                pars.push(s);
            len++;
        }
        vector<string> ans;
        for(auto s : temp) {
            if(s.length() == 2*n && isValidParenthesis(s))
                ans.push_back(s);
        }
        return ans;
    }

    bool isValid(string s) {
        int cnt_o = 0;
        int cnt_c = 0;
        for(auto i : s) {
            if (cnt_c > cnt_o)
                return false;
            else {
                if(i == '(')
                    cnt_o++;
                else
                    cnt_c++;
            }
        }
        return cnt_o >= cnt_c;
    }

    bool isValidParenthesis(string s) {
        int cnt_o = 0;
        int cnt_c = 0;
        for(auto i : s) {
            if (cnt_c > cnt_o)
                return false;
            else {
                if(i == '(')
                    cnt_o++;
                else
                    cnt_c++;
            }
        }
        return cnt_o == cnt_c;
    }
};
