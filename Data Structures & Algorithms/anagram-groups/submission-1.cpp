class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;

        for (auto & a: strs) {
            vector<int> count(26,0);
            for ( auto &c: a) {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for ( int i = 1; i <26; ++i) {
                key += ','+ to_string(count[i]);
            }
            hash[key].push_back(a);

        }
        vector<vector<string>> res;
        for (auto& pair:hash) {
            res.push_back(pair.second);
        }

        return res;
    }
};
