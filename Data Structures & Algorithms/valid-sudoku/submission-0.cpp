class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int row = 0; row < 9; ++row) {
            int arr[9] = {0};
            for (int i = 0; i < 9; ++i) {
                if (board[row][i] == '.') continue;
                int val = board[row][i] - '1'; // Convert '1'-'9' to 0-8
                if (arr[val] == 1) return false; // Number already seen
                arr[val] = 1;
            }
        }

        // Check columns
        for (int col = 0; col < 9; ++col) {
            int arr[9] = {0};
            for (int i = 0; i < 9; ++i) {
                if (board[i][col] == '.') continue;
                int val = board[i][col] - '1'; // Convert '1'-'9' to 0-8
                if (arr[val] == 1) return false; // Number already seen
                arr[val] = 1;
            }
        }

        // Check 3x3 subgrids
        for (int sq = 0; sq < 9; ++sq) {
            int arr[9] = {0};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int row = (sq / 3) * 3 + i;
                    int col = (sq % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    int val = board[row][col] - '1'; // Convert '1'-'9' to 0-8
                    if (arr[val] == 1) return false; 
                    arr[val] = 1;
                }
            }
        }

        return true; 
    }
};
