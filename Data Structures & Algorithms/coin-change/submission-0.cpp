class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        int count = dfs(amount,coins);
        return count == INT_MAX? -1: count;
    }

    int dfs( int amt, vector<int>& coins) {

        if (amt == 0) return 0;

        if(memo.find(amt) != memo.end()) {
            return memo[amt];
        }
        int mini = INT_MAX;
        for(int coin: coins) {
            if(amt-coin >= 0) {
                int res = dfs(amt-coin, coins);
                if(res != INT_MAX)
                    mini = min(mini,1+res);
            }
        }
        memo[amt] = mini;
        return mini;
    }
};
