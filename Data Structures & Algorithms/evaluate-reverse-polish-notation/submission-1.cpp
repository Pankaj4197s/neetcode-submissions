class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto c :  tokens) {
            if (c == "*") {
                int r = nums.top();nums.pop();
                int l = nums.top();nums.pop();
                nums.push(l*r);
            } else if (c == "+") {
                int r = nums.top();nums.pop();
                int l = nums.top();nums.pop();
                nums.push(l+r);
            } else if (c == "-") {
                int r = nums.top();nums.pop();
                int l = nums.top();nums.pop();
                nums.push(l-r);
            } else if (c == "/") {
                int r = nums.top();nums.pop();
                int l = nums.top();nums.pop();
                nums.push(l/r);
            } else {
                nums.push(stoi(c));
            }
        }
        return nums.top();
    }
};
