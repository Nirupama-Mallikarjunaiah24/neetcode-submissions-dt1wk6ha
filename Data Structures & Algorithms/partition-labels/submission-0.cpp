class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;

        for(int i = 0; i < s.size(); ++i) {
            last[s[i]] = i;
        }
        vector<int> res;
        int end = 0;
        int i = 0;
        while ( i < s.size()) {
            end = last[s[i]];
            int j = i+1;
            while (j < end) {
                end = max (end, last[s[j]]);
                j++;
            }
            res.push_back(end-i+1);
            i = end+1;
        }

        return res;
    }
};
