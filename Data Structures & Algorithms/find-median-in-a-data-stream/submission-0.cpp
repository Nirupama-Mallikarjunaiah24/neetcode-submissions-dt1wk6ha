class MedianFinder {
    priority_queue<int,vector<int>,less<int>> smallh;
    priority_queue<int,vector<int>,greater<int>> largeh;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallh.push(num);
        if ( !largeh.empty() && smallh.top() > largeh.top()) {
            largeh.push(smallh.top());
            smallh.pop();
        }
        if (smallh.size() > largeh.size() + 1) {
            largeh.push(smallh.top());
            smallh.pop();
        }
        if ( largeh.size() > smallh.size()+1) {
            smallh.push(largeh.top());
            largeh.pop();
        }
    }
    
    double findMedian() {
        if ( smallh.size() == largeh.size()) {
            return ( largeh.top() + smallh.top())/2.0;
        } else if ( smallh.size() > largeh.size()) {
            return smallh.top();
        } else {
            return largeh.top();
        }
    }
};
