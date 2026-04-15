class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> parts;
        int n = num1.size();
        for(auto c1 : num1) {
            int m = num2.size();
            for(auto c2 : num2) {
                int d1 = c1 - '0';
                int d2 = c2 - '0';
                int mul = d1*d2;
                int numZeros = n+m-2;
                string res = to_string(mul);
                while(numZeros && res != "0") {
                    res += '0';
                    numZeros--;
                }
                m--;
                parts.push_back(res);
            }
            n--;
        }
        string res = "0";
        for(auto p : parts) 
            res = add(res, p);
        return res;
    }

    string add(string num1, string num2) {
        int n = num1.size()-1;
        int m = num2.size()-1;
        int carry = 0;
        string res = "";
        while(n >= 0 || m >= 0 || carry != 0) {
            int d1 = (n >= 0) ? num1[n] - '0' : 0;
            int d2 = (m >= 0) ? num2[m] - '0' : 0;
            int sum = d1 + d2 + carry;
            int d = sum%10;
            carry = sum/10;
            res = to_string(d) + res;
            n--;
            m--;
        }
        return res;
    }
};
