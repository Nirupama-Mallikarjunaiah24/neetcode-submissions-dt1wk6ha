class StockSpanner {
    stack<int> ogstack;
    //int i
public:
    StockSpanner() {
       // i = 0;
    }
    
    int next(int price) {
        //int i = ogstack.top().second;
        //i++;
        int count = 0;
        ogstack.push(price);
        stack<int> s = ogstack;

        while (!s.empty() && s.top() <= price) {
            s.pop();
            count++;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */