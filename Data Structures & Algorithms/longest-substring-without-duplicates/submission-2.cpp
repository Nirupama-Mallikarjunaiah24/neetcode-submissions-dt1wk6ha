class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window but the dynamic size 
        // we kep expnading the window until all elements in the window are unique
        // if duplicate found the nwe erase until that point of duplicate is gone
        // the new start is the point that is next to the duplicate now and we insert the duplicate too and continue expanding the window
        if (s.length() == 0) {
            return 0;
        } 
        int n = s.length();
        unordered_set<char> charset;
        int i = 0;
        int maxlen = 0;
        
        for ( int j = 0; j < n; ++j) {
            while( charset.find(s[j]) != charset.end()) { // we found duplicate
                charset.erase(s[i]); // move the window until it is removed
                ++i;
            }
            charset.insert(s[j]);
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen;
        }

    };

