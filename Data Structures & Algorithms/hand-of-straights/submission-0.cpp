class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize)
            return false;
        map<int, int> cnt;
        for(auto h : hand)
            cnt[h]++;
        while(!cnt.empty()) {
            auto itr = cnt.begin();
            int start = itr->first;
            cnt[start]--;
            if (cnt[start] == 0)
                cnt.erase(start);
            for(int i=1;i<groupSize;i++) {
                if (cnt.find(start + i) != cnt.end()) {
                    cnt[start + i]--;
                    if (cnt[start + i] == 0)
                        cnt.erase(start + i);
                } else {
                    return false;
                }
            }
        }
        return cnt.size() == 0;
    }
};
