class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        // 1. Find pivot (index of minimum)
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r])
                r = m;
            else
                l = m + 1;
        }

        int pivot = l;

        if (target >= nums[pivot] && target <= nums[n-1]) {
            l = pivot;
            r = n-1;
        } else {
            l = 0;
            r = pivot - 1;
        }

        while (l <= r) {
            int m = l + (r-l)/2;

            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
