class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> sol;
        // vector is sorted so keep moving up and down
        while ( l < r) {
            if ( numbers[l] + numbers[r] == target) {
                sol.push_back(l+1);
                sol.push_back(r+1);
                return sol;
            } else if ( numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            }
        }

        return sol;
    }
};
