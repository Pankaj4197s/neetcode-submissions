class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        if (!maxHeap.empty() && minHeap.top() > maxHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (double) (minHeap.top() + maxHeap.top()) / 2;
        }
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};
