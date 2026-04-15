class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size();
        int u = 0;
        int d = matrix.size();
        int dir = 1; // 1 l to r, 2 up to down, 3 right to left, 4 down to up
        int col = 0;
        int row = 0;
        vector<int> order;
        while(l < r && u < d) {
            if (dir == 1) {
                if (col < r) {
                    order.push_back(matrix[row][col]);
                    col++;
                } else {
                    col = r - 1;
                    dir = 2;
                    row++;
                    u++;
                }
            } else if (dir == 2) {
                if (row < d) {
                    order.push_back(matrix[row][col]);
                    row++;
                } else {
                    row = d - 1;
                    dir = 3;
                    col--;
                    r--;
                }
            } else if (dir == 3) {
                if (col >= l) {
                    order.push_back(matrix[row][col]);
                    col--;
                } else {
                    col = l;
                    dir = 4;
                    row--;
                    d--;
                }
            } else {
                if (row >= u) {
                    order.push_back(matrix[row][col]);
                    row--;
                } else {
                    row = u;
                    dir = 1;
                    col++;
                    l++;
                }
            }
        }
        return order;
    }
};
