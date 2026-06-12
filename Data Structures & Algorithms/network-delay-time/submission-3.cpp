class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;
        for(const auto& time:times) {
            edges[time[0]].push_back({time[1],time[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minheap;
        minheap.push({0,k});
        set<int> visited;
        int t = 0;
        while ( !minheap.empty()) {
            auto curr = minheap.top();
            minheap.pop();
            if(visited.count(curr.second) != 0) {
                continue;
            }
            visited.insert(curr.second);
            t = curr.first;
            if(edges.count(curr.second) !=0) { // it has neighbors
                for ( const auto& next : edges[curr.second]) {
                    int n = next.first, w = next.second;

                    if ( visited.count(n) == 0) { //if not already visited, calculte its distance and add to minheap
                        minheap.push({w+curr.first, n});
                    }
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
