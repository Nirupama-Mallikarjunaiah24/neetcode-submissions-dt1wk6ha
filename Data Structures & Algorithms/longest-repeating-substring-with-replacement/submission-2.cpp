class Solution {
public:
    int characterReplacement(string s, int k) {
      int st = 0, res=0,maxf=0;
        unordered_map<char,int> hash;
      for ( int e = 0; e < s.size(); ++e) {
            hash[s[e]]++;
            maxf = max(maxf,hash[s[e]]);
            if (e-st+1 -maxf <= k){
                res = max (res, e-st+1);
            } else {
                while (e-st+1 -maxf > k) {
                    hash[s[st]]--;
                    st++;
                }
            }
      }
      return res;
    }
};
