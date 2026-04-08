class Solution {
public:
    vector<vector<int>> memo;

    int minDistance(string word1, string word2) {
        memo.assign(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string &w1, string &w2, int i, int j) {
        if (i == w1.size()) return w2.size() - j;
        if (j == w2.size()) return w1.size() - i;

        if (memo[i][j] != -1) return memo[i][j];

        if (w1[i] == w2[j]) {
            return memo[i][j] = dfs(w1, w2, i+1, j+1);
        }

        int insertOp = dfs(w1, w2, i, j+1);
        int deleteOp = dfs(w1, w2, i+1, j);
        int replaceOp = dfs(w1, w2, i+1, j+1);

        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
};
