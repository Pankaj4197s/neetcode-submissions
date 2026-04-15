class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        // Search for x1 = x and y1 = y+d or y-d (d = abs(y1-y))
        for(auto k : points[x]) {
            int y1 = k.first;
            int cnt = k.second;
            int d = y1 - y;
            if (d == 0)
                continue;
            int x2 = x + d, x3 = x - d;
            ans += cnt * points[x2][y1] * points[x2][y];
            ans += cnt * points[x3][y1] * points[x3][y];
        }
        return ans;
    }
};
