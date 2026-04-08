class MinStack {
    std::stack<int> stack;
    std::stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if ( min.empty()){ // first element
            min.push(val);
        } else { // not first element - compare with previous element
            if(min.top() < val) {
                min.push(min.top());
            } else {
                min.push(val);
            }
        }
        stack.push(val);
    }
    
    void pop() {
        if(stack.empty())
        return;
        stack.pop();
        min.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
