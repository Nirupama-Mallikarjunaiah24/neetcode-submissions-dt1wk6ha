class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value; 
        if (nums.size() < 2)
            return {};
        for ( int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (value.count(diff)) {
                return {value[diff],i};
            }
            value[nums[i]] = i;
        }

        return {};
    }
};
