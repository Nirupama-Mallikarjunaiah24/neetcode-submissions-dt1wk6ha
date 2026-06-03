class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size()-1;
        while ( l < r) {
            for ( int i = 0; i < r-l; ++i ) {
                int temp = matrix[l][l+i];
                matrix[l][l+i] = matrix[r-i][l];
                matrix[r-i][l] = matrix[r][r-i];
                matrix[r][r-i] = matrix[l+i][r];
                matrix[l+i][r] = temp;
            }
            l++; r--;
        }
    }
};
