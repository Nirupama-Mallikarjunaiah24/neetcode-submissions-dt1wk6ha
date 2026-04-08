class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        
        for( auto& pt : points) {
            int dist = pt[0]*pt[0] + pt[1]*pt[1];
            maxh.push({dist,{pt[0],pt[1]}});
            if(maxh.size() > k) {
                maxh.pop();
            }
        }

        vector<vector<int>> res;
        while( !maxh.empty()) {
            res.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return res;
    }
};
