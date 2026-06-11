class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        for ( int i = 0; i < n; ++i) {
            for (int j = 0; j <m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                        fresh++;
                }

            }
        }
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0}, {-1,0}};

        while (fresh>0 && !q.empty()) {
            int length = q.size();
            for (int j = 0; j < length; ++j) {
            auto curr = q.front();
            q.pop();
            for ( int i = 0; i< 4; ++i) {
                int dr = curr.first + directions[i].first;
                int dc = curr.second + directions[i].second;
                if (dr >=0 && dr < n && dc >=0 && dc < m && grid[dr][dc] == 1) {
                    q.push({dr,dc});
                    grid[dr][dc] = 2;
                    fresh --;
                }
            }
            }
            time++;
        }
        if (fresh == 0)
            return time;
        else
            return -1;
    }
};
