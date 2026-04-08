class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);

        for ( auto& inter : intervals) {
            if (inter[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], inter[1]);
            } else {
                res.push_back(inter);
            }
        }

        return res;
    }
};
