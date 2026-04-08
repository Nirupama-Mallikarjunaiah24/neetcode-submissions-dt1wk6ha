#include<unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> tables;
        std::unordered_map<char,int> tablet;
        int sizes = s.size();
        int sizet = t.size();
        if (sizes != sizet)
            return false;
        
        for(int i = 0; i < sizes; ++i) {
            tables[s[i]]++;
            tablet[t[i]]++;
        }
        return tables==tablet;
    }
};
