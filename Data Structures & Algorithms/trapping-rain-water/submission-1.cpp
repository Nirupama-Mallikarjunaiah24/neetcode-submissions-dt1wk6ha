class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.empty()) {
            return 0;
        }
        int s = height.size();
        int total_area = 0;
        int suffix[s],prefix[s];
        prefix[0] = height[0]; // left
        for ( int i = 1 ; i < s; ++i) {
            prefix[i] = max (prefix[i-1], height[i]);
        }
        suffix[s-1] = height[s-1] ; //right
        for ( int i = s-2; i >= 0; --i) {
            suffix[i] = max ( suffix[i+1], height[i]);
        }
        for ( int i = 0; i < s; ++i) {
            total_area += min(suffix[i], prefix[i]) - height[i];
        }
        return total_area;
    }
};
