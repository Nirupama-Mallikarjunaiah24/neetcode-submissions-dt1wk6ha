class Solution {
public:
    bool isPalindrome(string s) {
        int i,j;

        i = 0; j = s.size()-1;

        while ( i < j) {
            while ( i <j && !isalnum(s[i])) {
                i++;
            }
            
            while(j>i && !isalnum(s[j])) {
                j--;
            }
            
            if (tolower(s[i]) == tolower(s[j])) {
                i++;j--;
            } else {
                return false;
            }
                
        }
        return true;
    }

    
};
