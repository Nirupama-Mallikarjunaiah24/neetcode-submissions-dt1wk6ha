class Solution {
public:
    int maxProfit(vector<int>& prices) {
// reverse the idea. Assume that i is the selling day not buying
      int b = 0, s = 1;
      int maxp = 0;

      while ( s < prices.size()) {
            if ( prices[s] > prices[b]) {
                maxp = max (maxp, prices[s]-prices[b]);
            } else {
                b = s;
            }
            s++;
      }
      return maxp;
    }
};

// 10 1 5 6 7 1
