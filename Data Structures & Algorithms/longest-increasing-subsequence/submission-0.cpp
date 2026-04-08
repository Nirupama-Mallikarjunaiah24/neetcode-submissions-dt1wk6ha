class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs( nums, 0,-1);

    }

    int dfs(vector<int>& nums, int i, int j) {
        if ( i == nums.size()) {
            return 0;
        }

        int res = dfs(nums,i+1,j);

        if(j == -1 || nums[j] < nums[i]) {
            res = max(res, 1 + dfs(nums,i+1,i));
        }
        return res;
    }
};
