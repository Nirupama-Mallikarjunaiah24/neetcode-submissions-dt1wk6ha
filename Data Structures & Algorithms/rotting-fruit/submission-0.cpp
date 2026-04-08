class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        queue<pair<int,int>> q;

        for ( int i = 0; i <n; ++i) {
            for ( int j =0 ; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                
                } else if ( grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;

        while ( !q.empty()) {
            int s = q.size();
            bool rotten = false;

            for ( int i = 0; i < s; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x-1 >=0 && grid[x-1][y] == 1) {
                    rotten = true;
                    q.push({x-1,y});
                    grid[x-1][y] = 2;
                    fresh--;
                }
                if (x+1 <n && grid[x+1][y] == 1) {
                    rotten = true;
                    q.push({x+1,y});
                    grid[x+1][y] = 2;
                    fresh--;
                }
                if (y-1 >= 0 && grid[x][y-1] == 1) {
                    rotten = true;
                    q.push({x,y-1});
                    grid[x][y-1] = 2;
                    fresh--;
                }
                if (y+1 < m && grid[x][y+1] == 1) {
                    rotten = true;
                    q.push({x,y+1});
                    grid[x][y+1] = 2;
                    fresh--;
                }
            }
            if ( rotten == true)
                minutes++;
        }

        if (fresh == 0) return minutes;

        return -1;

    }
};