class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        for ( int i = 0; i < n; ++i) {
            for ( int j = 0; j < m; ++j) {
                if( grid[i][j] == '1') {
                    bfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }

    void bfs(int r, int c, vector<vector<char>>& grid) {
        int diri[4] = {-1,1,0,0};
        int dirj[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r,c});

        while ( !q.empty()) {
            auto node = q.front();
            q.pop();
            
            for ( int i = 0; i <4; ++i) {
                int nr = node.first + diri[i];
                int nc = node.second + dirj[i];

                if (nr >=0 && nc >=0 && nr <grid.size() && nc <grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }

    }
};
