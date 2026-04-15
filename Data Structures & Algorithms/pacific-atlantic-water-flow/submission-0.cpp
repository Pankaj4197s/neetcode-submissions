// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         set<pair<int, int>> pacific;
//         set<pair<int, int>> atlantic;
//         int n = heights.size();
//         int m = heights[0].size();
//         // Pacific
//         for(int i=0;i<m;i++)
//             pacific.insert({0,i});
//         for(int i=0;i<n;i++)
//             pacific.insert({i,0});
//         // Atlantic
//         for(int i=0;i<m;i++)
//             pacific.insert({n-1,i});
//         for(int i=0;i<n;i++)
//             pacific.insert({i,m-1});
//         // DFS for Pacific
//         set<pair<int, int>> pac;
//         set<pair<int, int>> visited;
//         for(int i=0;i<n;i++) {
//             for(int j=0;i<m;j++) {
//                 if (dfs(heights, pacific, i, j, n, m, visited))
//                     pac.insert({i,j});
//             }
//         }
//         for(auto p : pac)
//             cout<<p.first<<" "<<p.second<<endl;
//         return {};
//     }

//     bool dfs(vector<vector<int>>& heights, set<pair<int, int>>& pacific, int i, int j, int n, int m,
//     set<pair<int, int>>& visited) {
//         if (i < 0 || j < 0 || i >= n || j >= m)
//             return false;
        
//         if (pacific.find({i, j}) != pacific.end())
//             return true;

//         if (visited.find({i,j}) == visited.end()){
//             visited.insert({i,j});
//             if (isValid(i+1,j,n,m) && heights[i+1][j] <= heights[i][j] && 
//             dfs(heights, pacific, i+1, j, n, m, visited))
//                 return true;
//             if (isValid(i-1,j,n,m) && heights[i-1][j] <= heights[i][j] && 
//             dfs(heights, pacific, i-1, j, n, m, visited))
//                 return true;
//             if (isValid(i,j+1,n,m) && heights[i][j+1] <= heights[i][j] && 
//             dfs(heights, pacific, i, j+1, n, m, visited))
//                 return true;
//             if (isValid(i,j-1,n,m) && heights[i][j-1] <= heights[i][j] && 
//             dfs(heights, pacific, i, j-1, n, m, visited))
//                 return true;
//         }
//         return false;
//     }

//     bool isValid(int i, int j, int n, int m) {
//         if (i < 0 || j < 0 || i >= n || j >= m)
//             return false;
//         return true;
//     }
// };
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacificReachable(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticReachable(n, vector<bool>(m, false));

        // Initialize starting points
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacificReachable, 0, i, INT_MIN); // Pacific (top row)
            dfs(heights, atlanticReachable, n - 1, i, INT_MIN); // Atlantic (bottom row)
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, pacificReachable, i, 0, INT_MIN); // Pacific (left column)
            dfs(heights, atlanticReachable, i, m - 1, INT_MIN); // Atlantic (right column)
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int i, int j, int prevHeight) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
            return;
        }
        if (heights[i][j] < prevHeight) {
            return;
        }
        if (reachable[i][j]) {
            return; // Already visited and reachable
        }

        reachable[i][j] = true;

        dfs(heights, reachable, i + 1, j, heights[i][j]);
        dfs(heights, reachable, i - 1, j, heights[i][j]);
        dfs(heights, reachable, i, j + 1, heights[i][j]);
        dfs(heights, reachable, i, j - 1, heights[i][j]);
    }
};
