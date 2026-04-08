class Solution {
public:
    string longestPalindrome(string s) {
        int strlen = 0, stridx = 0;

        for ( int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while ( l >=0 && r<s.size() && s[l] == s[r]) {
                if(r-l+1 > strlen) {
                    stridx = l;
                    strlen = r-l+1;
                }
                l--;r++;
            }

            l = i; r = i+1;
            while ( l >=0 && r<s.size() && s[l] == s[r]) {
                if(r-l+1 > strlen) {
                    stridx = l;
                    strlen = r-l+1;
                }
                l--;r++;
            }
        }

        return s.substr(stridx,strlen);
    }
};
