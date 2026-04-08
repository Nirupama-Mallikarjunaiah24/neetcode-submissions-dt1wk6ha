class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s2cnt[26] = {0};
        int s1cnt[26] = {0};
        int n = s1.size();
        int m = s2.size();

        if ( n > m ) {
            return false;
        }
        // s1 is shorter
        // s2 is longer

        for ( int i = 0; i < n; ++i) {
            s2cnt[s2[i] - 'a'] ++;
            s1cnt[s1[i] - 'a'] ++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
             if ( s2cnt[i] == s1cnt[i]) {
                ++matches;
            }
        }

        if (matches == 26)
          return true;
        
        // starting of the window
        for ( int i = n, j = 0; i < m; ++i, ++j) { // ending of the window which we move 
            if (matches == 26)
                return true;

            int newidx = s2[i] - 'a'; // new end of the slide
            s2cnt[newidx]++;
            if (s2cnt[newidx] == s1cnt[newidx]) { // now count matched then increase
                matches++;
            } else if ( s1cnt[newidx]+1 == s2cnt[newidx]){ // if the count already matched then have to undo it 
                matches--; }
            
            newidx = s2[j] - 'a'; // old beginning of the slide
            s2cnt[newidx]--;
            if (s2cnt[newidx] == s1cnt[newidx]) { // now count matched then increase
                matches++;
            } else if ( s1cnt[newidx]-1 == s2cnt[newidx]) { // if the count already matched then have to undo it 
                matches--; }
        }

        return matches == 26;
    }
};

/* brute force would be to sort both in and then search for the substirng is in it
but optimised would be to use hash table but with this i cant judge the order
so the next idea would be to maintain a an array of the letters and their counts
but can it be done in o(n)? */