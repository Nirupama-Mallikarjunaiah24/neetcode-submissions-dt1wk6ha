class Solution {
public:
    int characterReplacement(string s, int k) {
        // use sliding window and keep expanding it if the char already exists
        // if new char is encountered then change it and reduce k
        // again new char is encountered store the count
        // delete the char with higher count
        // move the window to the new beginning where the new char is
        // reset k - did not execute it

        // hash everything to get unique chars

        if ( s.size() == 0) {
            return 0;
        }
        int res = 0;
        unordered_set<char> charset(s.begin(),s.end());
        int n = s.size();
        for ( char c : charset) {
            int count = 0, l = 0;
            for ( int r = 0; r < n; ++r ) {
                if ( s[r] == c){ // counting the char in window
                    count++;
                }
                while((r-l+1)- count > k) { // while the other char is less greater k
                  if ( s[l] == c) {
                     count --;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};

