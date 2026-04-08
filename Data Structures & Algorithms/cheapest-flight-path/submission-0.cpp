class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k+5,INF)); // based on istance we will get the shortest

        for( auto& flight: flights) {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        dist[src][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
        minHeap.push({0,src,-1});

        while( !minHeap.empty()) {
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();
            if( node == dst) return cost;
            if( stops == k || dist[node][stops+1] < cost)
                continue;
            
            for( auto& [neigh,w]:adj[node]) {
                int nextcst = cost+w;
                int nextstops = stops+1;
                if(dist[neigh][nextstops+1]> nextcst) {
                    dist[neigh][nextstops+1] = nextcst;
                    minHeap.push({nextcst,neigh,nextstops});
                }
            }
        }
        return -1;
    }
};
