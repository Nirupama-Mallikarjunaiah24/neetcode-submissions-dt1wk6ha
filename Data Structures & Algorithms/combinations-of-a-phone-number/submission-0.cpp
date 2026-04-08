class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits.empty()) return {};

        vector<string> res = {""};
        vector<string> digittochar = {"","","abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz" };

        for( char digit: digits) {
            vector<string> tmp;
            for(string &cur: res) {
                for( char c: digittochar[digit-'0']) {
                    tmp.push_back(cur + c);
                }
            }
            res = tmp;
        }
        return res;
    }
};
