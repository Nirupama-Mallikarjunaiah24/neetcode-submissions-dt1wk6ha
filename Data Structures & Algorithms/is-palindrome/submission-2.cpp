class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while ( l < r) {
            while ( l < r && !alphanum(s[l]) ) {
                l++;
            }

            while (r>l && !alphanum(s[r])) {
                r--;
            }

            if ( tolower(s[l])!= tolower(s[r])) {
                return false;
            }

            l++; r--; // forgot to mve the pointer!! - DO NOT REPEAT
        }

        return true;
    }

    bool alphanum (char c) {
        if (c >= 'A' && c <= 'Z'|| c >='a' && c<='z' || c >= '0' && c <= '9')
            return true;
        else
            return false;
    }
};
