class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int area = 0;

        for ( int i = 0; i < heights.size(); ++i) {
            int start = i;
            while ( !stk.empty() && stk.top().second > heights[i]) {
                // pop and calc area
                    pair<int,int> ht = stk.top();
                    stk.pop();
                    area = max(area, ht.second*(i-ht.first));
                    start = ht.first;
                
            }
                stk.push({start,heights[i]});
                // extending backwards because that means this amount of area is stilll there
            
        }
// now i need to calc when the stk still has elements
        while ( !stk.empty()) {
            pair<int,int> ht = stk.top();
            area = max( area, ht.second*static_cast<int>(heights.size() - ht.first));
            stk.pop();
        }
        return area;
    }
};
