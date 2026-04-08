class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        int first,second,res;
        for ( string s: tokens) {
            if (s == "*") {
                first = stack.top();stack.pop();
                second = stack.top();stack.pop();
                res = second*first;
                stack.push(res);
            } else if (s == "+") {
                first = stack.top();stack.pop();
                second = stack.top();stack.pop();
                res = second+first;
                stack.push(res); 
            } else if (s == "-") {
                first = stack.top();stack.pop();
                second =stack.top(); stack.pop();
                res = second-first;
                stack.push(res);
            } else if (s == "/") {
                first = stack.top();stack.pop();
                second = stack.top();stack.pop();
                res = second/first;
                stack.push(res);
            } else {
                stack.push(std::stoi(s));
            }
        }
        return stack.top();
    }
};
