class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for (auto t: times) {
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dfs(k,0,adj,dist);
        int res = *max_element(dist.begin()+1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
private:
    void dfs(int node, int time, unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& dist) {
        if(time >= dist[node]) return;
        dist[node] = time;
        for ( auto& [neigh, weight] : adj[node]) {
            dfs(neigh, time+weight, adj,dist);
        }
    }
};
