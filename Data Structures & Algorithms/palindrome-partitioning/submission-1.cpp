class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allParts;
        vector<string> temp;
        getAllParts(s, allParts, temp);
        return allParts;
    }

    void getAllParts(string s, vector<vector<string>>& allParts, vector<string>& temp) {
        int n = s.size();
        if (s.empty()) {
            allParts.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++) {
            string first = s.substr(0, i+1);
            if (isPalindrome(first)) {
                string last = s.substr(i+1);
                temp.push_back(first);
                getAllParts(last, allParts, temp);
                temp.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r == s;
    }
};
