class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses,0);
        vector<vector<int>> mp(numCourses); // because we already know the size we take vecotr not hashmap
        for( auto & pre: prerequisites) {
            indegree[pre[0]]++;
            mp[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        vector<int> order;
        for (int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while ( !q.empty()){
            int node = q.front(); q.pop();
            order.push_back(node);
            for(auto& neigh:mp[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if(order.size() == numCourses)
            return order;

        return {};

    }
};
// topological - build the adjacency matrix and indegree vlist
// use bfs and add value with 0 indegree to the queues and do bfs and reduce for neightbors being visited
// if zer indegree add to queue
// if finally the order is same length as the number of node - order is the result
// else cycle is detected