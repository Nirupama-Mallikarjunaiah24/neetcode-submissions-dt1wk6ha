class Solution {
public:
    vector<int> house;
    int rob(vector<int>& nums) {
        house.resize(nums.size(),-1);
        return dfs(nums,0);
    }

    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;
        
        if (house[i] != -1)
            return house[i];
        
        house[i] = max(nums[i]+dfs(nums,i+2), dfs(nums,i+1));
        return house[i];
    }

};
