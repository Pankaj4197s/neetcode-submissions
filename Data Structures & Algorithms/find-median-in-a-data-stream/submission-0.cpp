class MedianFinder {
public:
    priority_queue<int> stream;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        this->stream.push(num);
    }
    
    double findMedian() {
        priority_queue<int> nums = this->stream;
        int n = nums.size();
        double mean;
        if (n%2) {
            int k = n/2;
            while(k--) {
                nums.pop();
            }
            mean = (double)nums.top();
        } else {
            int k = n/2 - 1;
            while(k--) {
                nums.pop();
            }
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            mean = (double)(a+b)/2;
        }
        return mean;
    }
};
