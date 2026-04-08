class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row,top = 0, bottom = n-1;

        while ( top <=bottom) {
            row = (top +bottom)/2;
            if (target < matrix[row][0]) {
                bottom = row - 1;
            } else if (target > matrix[row][m - 1]) {
                top = row + 1;
            } else {
                break; // target lies in this row
            }
        }
        if ( top > bottom) {
            return false;
        }
        top = 0; bottom = m-1; // columns are traversed

        while ( top <= bottom) {
            int mid = (top + bottom)/2;
            if ( target > matrix[row][mid]) {
                top = mid+1;
            } else if ( target < matrix[row][mid]) {
                bottom = mid-1;
            } else {
                return true;
            }
        }
        return false;
    }
};
