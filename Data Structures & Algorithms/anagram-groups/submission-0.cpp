class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(auto s : strs) {
            string val = s;
            sort(s.begin(), s.end());
            string key = s;
            if (anagrams.find(key) != anagrams.end()) {
                anagrams[key].push_back(val);
            } else {
                anagrams[key] = {val};
            }
        }
        vector<vector<string>> ans;
        for(auto an : anagrams) {
            ans.push_back(an.second);
        }
        return ans;
    }
};
