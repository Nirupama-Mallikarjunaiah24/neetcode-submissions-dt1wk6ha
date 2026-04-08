class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nummap;

        for ( int i = 0; i < nums.size(); ++i) {
            nummap[nums[i]] = i;
        }

        for ( int i = 0; i < nums.size(); ++i) {
            if (nummap.count(target - nums[i]) && nummap[target-nums[i]] != i) {
                return {i,nummap[target-nums[i]]};
            }
        }
        return {};
    }
};
