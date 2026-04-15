class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        for (auto i : cars)
            cout << "A: " << i.first << " " << i.second << endl;
        stack<pair<int, int>> behind;
        double timeE = 0.0;
        for (int i = 0; i < n; i++) {
            bool insert = true;
            // cout << "Size of stack: " << behind.size() << endl;
            while (!behind.empty()) {
                if (behind.top().first <= cars[i].first &&
                    behind.top().second > cars[i].second) {
                    // A car behind or at the same place has speed >= this car.
                    // So, they meet up and form a fleet.
                    int f_speed = min(behind.top().second, cars[i].second);
                    double time =
                        ((double)cars[i].first - (double)behind.top().first) /
                        ((double)behind.top().second - (double)cars[i].second);
                    double dist = time * (double)behind.top().second;
                    double meet = (double)behind.top().first + dist;
                    cout << f_speed << endl;
                    cout << meet << endl;
                    if (meet <= target) {
                        behind.pop();
                        // cout << "Size of stack after pop: " << behind.size()
                            //  << endl;
                        // behind.push({(int)meet, f_speed});
                        // cout << "Size of stack after insert: " << behind.size()
                            //  << endl;
                        cars[i] = {cars[i].first, f_speed};
                        timeE == time;
                    } else {
                        behind.push(cars[i]);
                        insert = false;
                        break;
                    }
                } else {
                    behind.push(cars[i]);
                    insert = false;
                    break;
                }
            }
            if (insert)
                behind.push(cars[i]);
        }
        return behind.size();
    }
};