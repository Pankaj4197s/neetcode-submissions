class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = m-1;
        while(l <= h) {
            int midR = (l + h)/2;
            if (target < matrix[midR][0]) {
                h--;
            } else if (target > matrix[midR][n-1]) {
                l++;
            } else {
                int lc = 0;
                int hc = n-1;
                while (lc <= hc) {
                    int midC = (lc + hc)/2;
                    if (target < matrix[midR][midC]) {
                        hc--;
                    } else if (target > matrix[midR][midC]) {
                        lc++;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
