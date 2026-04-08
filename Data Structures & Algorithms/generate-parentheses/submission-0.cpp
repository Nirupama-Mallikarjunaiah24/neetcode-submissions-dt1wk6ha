class Solution {
public:
    void backtrack ( int openn, int closedn, int n, vector<string>& res, string& stack) {
        if(openn == closedn && openn == n) {
            res.push_back(stack);
            return;
        }
        if ( openn < n) {
            stack +='(';
            backtrack(openn+1, closedn, n, res,stack);
            stack.pop_back();
        }

        if ( closedn < openn) {
            stack +=')';
            backtrack(openn, closedn+1, n, res,stack);
            stack.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
};
