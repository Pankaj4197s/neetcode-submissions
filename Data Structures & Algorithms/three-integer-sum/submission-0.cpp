class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            int target = nums[i]*-1;
            set<vector<int>> res = twoSum(nums, target, i);
            for(auto j : res)
                ans.push_back(j);
        }
        return ans;
    }

    set<vector<int>> twoSum(vector<int>& numbers, int target, int exc) {
        unordered_map<int, int> diff;
        set<vector<int>> ans;
        for(int i = exc + 1; i < numbers.size(); i++) {
            if (i == exc) {
                continue;
            } else {
                vector<int> res;
                int complement = target - numbers[i];
                if (diff.find(complement) != diff.end()) {
                    res.push_back(numbers[i]);
                    res.push_back(diff[complement]);
                    res.push_back(numbers[exc]);
                    sort(res.begin(), res.end());
                    ans.insert(res);
                }
                diff[numbers[i]] = numbers[i];
            }
        }
        for(auto i : ans) {
            for(auto j:i)
                cout<<j<<endl;
            cout<<"asad"<<endl;
        }
        return ans;
    }
};