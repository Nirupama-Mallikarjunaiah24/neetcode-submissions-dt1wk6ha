class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        std::stack<char> stack;
        std::unordered_map<char,char> match = {
            {')', '('},
            {']','['},
            {'}','{'} };

        for (int i = 0; i < n; ++i) {
            if (match.count(s[i])) { // it is closing bracket
                cout<< s[i]<<"closed\n";
                if (!stack.empty() && stack.top() == match[s[i]]) {
                    stack.pop(); // match found
                } else {
                    return false; 
                }
            } else {
                cout << s[i];
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};

// {{}()}