class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) { // right side is sorted
                r = m; // look in left
            } else { // left side is sorted
                l = m + 1; // look in right
            }
        }
        return nums[l]; // also the pivot point
    }
};