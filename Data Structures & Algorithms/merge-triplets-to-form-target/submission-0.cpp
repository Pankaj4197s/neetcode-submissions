class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res = triplets[0];
        for(int i=0;i<triplets.size();i++) {
            // Check if current triplet needs to discarded
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            if (triplets[i] == target)
                return true;
            res[0] = max(res[0], triplets[i][0]);
            res[1] = max(res[1], triplets[i][1]);
            res[2] = max(res[2], triplets[i][2]);
            if (res == target)
                return true;
        }
        return false;
    }
};
