class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        if ( strs.empty()) 
            return res;

        for ( auto & s: strs) {
            res += to_string(s.size())+','+s; // assuming that the string only has letter or doesnt end with numbers
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        for (int i = 0; i< s.size(); ++i) {
            int j = i;
            while(s[j] != ',') { // i got the string that holds the number
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            strs.push_back(s.substr(j+1, len));
            i = j+len;
        }

        return strs;
    }
};
