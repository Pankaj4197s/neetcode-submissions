class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        sort(piles.begin(), piles.end());
        int hi = piles[piles.size()-1];
        int res = hi;
        while(l <= hi) {
            int mid = (hi+l)/2;
            int hrs = 0;
            for(auto i:piles)
                hrs += (i/mid + (i%mid > 0 ? 1 : 0));
            cout<<mid<<" "<<hrs<<endl;
            if (hrs <= h) {
                hi = mid-1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
