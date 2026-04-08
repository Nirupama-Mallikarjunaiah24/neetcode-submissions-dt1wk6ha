class Solution {
public:
    set<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        res.clear();
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(nums,target,0,subset,0);
        return vector<vector<int>>(res.begin(),res.end());
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& subset, int total) {

            if ( total == target) {
                res.insert(subset);
                return;
            }
            if ( total > target || i >= nums.size()) {
                    return;
            }

            subset.push_back(nums[i]);
            dfs(nums,target,i+1,subset, total+nums[i]);
            subset.pop_back();
            dfs(nums,target,i+1,subset, total);

    }
};
