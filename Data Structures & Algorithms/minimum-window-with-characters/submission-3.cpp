class Solution {
public:
    string minWindow(string s, string t) {
        
        if (t.empty())
            return "";

        unordered_map<char,int> hasht,hashwindow;

        for (char c: t) {
            hasht[c]++;
        }
        int match = 0, need = hasht.size(); 
        int len = INT_MAX;
        pair<int, int> res = {-1, -1};
        int first = 0; // because 0 is still valid index

        for (int i = 0; i < s.size(); ++i) {
            hashwindow[s[i]]++;

            if (hasht.count(s[i]) && hashwindow[s[i]] == hasht[s[i]]) {
                match++;
            } 

            while(match == need) {
                if ( i-first+1 < len) {
                    len = i-first+1;
                    res = {first, i};
                }
                hashwindow[s[first]]--;
                if (hasht.count(s[first]) &&hashwindow[s[first]] < hasht[s[first]]) {
                    match--;
                }
                first++;
            }
        }

        return len == INT_MAX ?"": s.substr(res.first,len);
    }
};
