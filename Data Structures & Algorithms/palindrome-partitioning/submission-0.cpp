class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allParts;
        vector<string> temp;
        getAllParts(s, allParts, temp);
        // vector<vector<string>> ans;
        // for(auto s : allParts) {
        //     int cnt = 0;
        //     for(auto t : s) {
        //         if (isPalindrome(t))
        //             cnt++;
        //     }
        //     if (cnt == s.size())
        //         ans.push_back(s);
        // }
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
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
