class MedianFinder {
    vector<int> v;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    
public:
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        small.push(num);
        
        large.push(small.top());
        small.pop();
        
        if(small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return (small.size() > large.size() ? small.top() : ((double) small.top()+large.top()) *0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */