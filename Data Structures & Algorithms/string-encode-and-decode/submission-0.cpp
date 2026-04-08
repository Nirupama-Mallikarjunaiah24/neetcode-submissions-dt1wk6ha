class Solution {
public:

    string encode(vector<string>& strs) {
        string en;
        for ( const auto& s : strs) {
            en += to_string(s.size()) + "#" +s;
        }
        return en;
    }

    vector<string> decode(string s) {

        vector<string> res;
        int i = 0;
        int n = s.size();
        while(i < n) {
            int j = i;
            while ( s[j] !='#') {
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            i = j +1;
            res.push_back(s.substr(i,length));
            i += length;
        }
        return res;
    }
};

/* US  has ASCII value 31, which is most likely not goijng to be used in the english language characters
and it is Unit seperator, so this is in a way not the same but maybe can be used*/

