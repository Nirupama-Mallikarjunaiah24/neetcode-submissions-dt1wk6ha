class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.length() == 0) {
            return 0;
        } 
        int n = s.length();
        unordered_set<char> charset;
        int i = 0;
        int maxlen = 0;
        
        for ( int j = 0; j < n; ++j) {
            while( charset.find(s[j]) != charset.end()) {
                charset.erase(s[i]); // move the window until it is removed
                ++i;
            }
            charset.insert(s[j]);
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen;
        }

    };

