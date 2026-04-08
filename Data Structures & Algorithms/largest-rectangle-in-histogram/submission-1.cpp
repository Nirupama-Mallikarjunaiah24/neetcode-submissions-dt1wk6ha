class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int,int>> stk;
        int maxarea = 0;

        for (int i = 0; i <heights.size(); ++i) {
                int idx = i; // to extend backwards
            while ( !stk.empty() && stk.top().second > heights[i]) {
                    auto pair = stk.top();
                    stk.pop();
                    maxarea = max ( maxarea, pair.second*(i-pair.first));
                    idx = pair.first;
            }
            stk.push({idx,heights[i]});
        }

        while(!stk.empty()) {
          auto pair = stk.top();
          stk.pop();
          maxarea = max (maxarea, pair.second*static_cast<int>(heights.size()-pair.first));
        }

        return maxarea;
    }
};
