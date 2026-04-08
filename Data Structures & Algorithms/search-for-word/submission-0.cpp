class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for ( int i = 0; i < board.size(); i ++) {
            for ( int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    bool res = dfs(word,board,0,i,j);
                    if ( res == true)
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs ( string word, vector<vector<char>>& board, int i, int r, int c) {
        if ( i == word.size())
            return true;
        
        if(r >= board.size() || r < 0 || c >= board[0].size() || c < 0 || board[r][c] != word[i] || board[r][c] == '#')
            return false;
        
        char tmp = board[r][c];
        board[r][c] = '#';
        bool res = dfs(word,board,i+1,r+1,c)|| dfs(word,board,i+1,r,c+1)|| dfs(word,board,i+1,r-1,c)|| dfs(word,board,i+1,r,c-1);
        board[r][c] = tmp;
        return res;
    }
};
