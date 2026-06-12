class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for ( int i = 0; i <n; ++i) {
            dist[i][i] = 0;
            for (auto & t :times) {
                int u = t[0]-1, v = t[1] -1, w = t[2];
                dist[u][v] = w;
            }
        }
        for ( int mid = 0; mid < n; ++mid) {
            for (int i = 0; i <n; ++i) {
                for ( int j = 0; j < n; ++j) {
                    dist[i][j] = min (dist[i][j], dist[i][mid]+dist[mid][j]);
                }
            }
        }
        int res = *max_element(dist[k-1].begin(),dist[k-1].end());
        return res == INT_MAX ? -1: res;
    }
};
