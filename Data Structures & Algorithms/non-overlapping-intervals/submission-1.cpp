class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int res = 0;
        
        for (int i = 1; i < intervals.size(); ++i ) {
            if (intervals[i][0] < end) {
                res++;
                end = min (end,intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }

        return res;   }
};
