class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0,nums,target);
    }

    int backtrack( int i, vector<int>& nums, int target) {
        if ( i == nums.size())
            return target == 0;
        return backtrack(i+1,nums,target-nums[i]) + backtrack(i+1, nums, target+nums[i]);
    }
};
