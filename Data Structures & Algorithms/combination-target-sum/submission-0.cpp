class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,target,0,subset,0,res);
        return res;
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& subset, int total, vector<vector<int>>& res) {

            if ( total == target) {
                res.push_back(subset);
                return;
            }
            if ( total > target || i >= nums.size()) {
                    return;
            }

            subset.push_back(nums[i]);
            dfs(nums,target,i,subset, total+nums[i],res);
            subset.pop_back();
            dfs(nums,target,i+1,subset,total,res);

    }
};
