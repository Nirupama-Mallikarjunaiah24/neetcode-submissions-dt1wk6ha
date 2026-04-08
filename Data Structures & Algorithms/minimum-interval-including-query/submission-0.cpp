class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),[](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> sortq = queries;
        sort(sortq.begin(), sortq.end());
        map<int,int> res;

        auto cmp = [](const vector<int>& a, const vector<int> &b) {
            return a[0] > b[0] || ( a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minh(cmp);
        int i = 0;
        for ( int q:sortq) {
            while (i < intervals.size() && intervals[i][0] <=q) {
                minh.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }
            while ( !minh.empty() && minh.top()[1] < q) {
                minh.pop();
            }
            res[q] = minh.empty() ? -1 : minh.top()[0];
        }

        vector<int> result(queries.size());
        for ( int i = 0; i < queries.size(); ++i) {
            result[i] = res[queries[i]];
        }
        return result;
    }
};
