class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(t.empty())
        return "";
        // s is longer
        // t is shorter
        unordered_map<char,int> countt, window;
        for ( char c: t) { // count of all chars in t
            countt[c]++;
        }

        int have = 0, need = countt.size();
        pair<int,int> res = {-1,-1};
        int reslen = INT_MAX;
        int l = 0;

        for ( int r = 0; r < s.length(); ++r) {
            char c = s[r];
            window[c]++;
            if( countt.count(c) && window[c] == countt[c]) {
                have++;
            }

            while( have == need) {
                if ((r-l+1) < reslen) {
                    reslen = r-l+1;
                    res = {l,r};
                }

                window[s[l]]--; // moving the window so reducing the count

                if(countt.count(s[l]) && window[s[l]] < countt[s[l]]) { // now if the count is lower that what is needed then reduce have too
                    have--;
                }
                l++;
            }

        }
        return reslen == INT_MAX ? "":s.substr(res.first,reslen);
        
    }
};

/* similar to the last question i would have to check for matches
but for the larger string it should be greater than or qual to not exactly equal coutn 
but how will i find the shortest string then? i cannot
so i need to go back to hashing and maintaining the count*/