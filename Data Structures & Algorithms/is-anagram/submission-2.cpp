class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);

        if ( s.size() != t.size())
            return false;
        
        for ( int i = 0; i < s.size(); ++i) {
            smap[s[i]-'a']++;
            tmap[t[i]-'a']++;
        }

        for ( int i = 0; i < 26; ++i) {
            if (smap[i] != tmap[i])
                return false;
        }
        return true;


    }
};
