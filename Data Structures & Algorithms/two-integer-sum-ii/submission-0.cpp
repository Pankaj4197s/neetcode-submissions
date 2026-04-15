class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> diff;
        vector<int> ans;
        for(int i = 0; i < numbers.size() ; i++) {
            int complement = target - numbers[i];
            if (diff.find(complement) != diff.end()) {
                ans.push_back(i+1);
                ans.push_back(diff[complement] + 1);
                sort(ans.begin(), ans.end());
                return ans;
            }
            diff[numbers[i]] = i;
        }
        return {};
    }
};
