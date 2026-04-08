class MinStack {

    vector<int> stack;
    vector<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty()) {
            min.push_back(val);
            stack.push_back(val); }

        else {
            if (min.back()> val) {
                min.push_back(val);
                stack.push_back(val);
            } else {
                min.push_back(min.back());
                stack.push_back(val);
            }
        }
    }
    
    void pop() {
        stack.pop_back();
        min.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};
