class KthLargest {
public:
    priority_queue<int> pq;
    int n;
    KthLargest(int k, vector<int>& nums) {
        for(auto i : nums)
            pq.push(i);
        n = k;
    }
    
    int add(int val) {
        int temp = n;
        pq.push(val);
        priority_queue<int> pqt = pq;
        while(temp > 1) {
            pqt.pop();
            temp--;
        }
        return pqt.top();
    }
};
