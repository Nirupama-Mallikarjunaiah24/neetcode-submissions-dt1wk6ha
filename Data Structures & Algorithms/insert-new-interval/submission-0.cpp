class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            auto& inter = *it;
            if(newInterval[1] < inter[0]) {
                res.push_back(newInterval); 
                res.insert(res.end(), it, intervals.end());
                return res;
            }
            else if (newInterval[0] > inter[1])
                res.push_back(inter);
            else {
                newInterval[0] = min(newInterval[0], inter[0]);
                newInterval[1] = max(newInterval[1], inter[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};