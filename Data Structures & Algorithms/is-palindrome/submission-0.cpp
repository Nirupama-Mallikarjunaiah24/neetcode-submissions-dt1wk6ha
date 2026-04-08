class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() -1;

        while ( l < r) {
            // ignore white spaces
            //both pointers wont encounter the white spaces at the same time
            // so deal with each seperately
            while (l < r && !(isalnum(s[l]))) {
                ++l;
            }
            while ( l < r && !(isalnum(s[r]))) {
                --r;
            } 
            if ( tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};

