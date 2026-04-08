class Solution {
public:
    bool isValid(string s) {
        vector<int> st;

        for (char c: s) {
            
            if (c == '[' || c == '{' || c == '(' ) {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char top = st.back(); st.pop_back();
                
                if ( top == '[' && c != ']' || top == '{' && c != '}' || top == '(' && c != ')') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
