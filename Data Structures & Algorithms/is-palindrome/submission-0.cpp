class Solution {
public:
    bool isPalindrome(string s) {
        // Remove all other characters other than alphanumeric
        // convert to lower/upper case
        unordered_map<char,bool> valid;
        string validChars = "0123456789abcdefghijklmnopqrstuvwxyz";
        for (auto i : validChars)
            valid[i] = true;
        
        string fr = "";
        for (auto c : s) {
            c = tolower(c);
            if (valid[c])
                fr += c;
        }
        string rev = "";
        for (int i=fr.length() - 1; i>=0;i--)
            rev += fr[i];
        return fr == rev;
    }
};
