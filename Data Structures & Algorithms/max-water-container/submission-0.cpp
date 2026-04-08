class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int s = heights.size();
        int i = 0; 
        int j = s-1;

        while ( i < j) {
            area = max (area,(j-i)* min(heights[i], heights[j]));
            if (heights[i] > heights[j]) 
                --j;
            else 
                ++i;
        }


        return area;
    }
};
