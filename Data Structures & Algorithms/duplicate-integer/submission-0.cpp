#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> table;
        int n = nums.size();
        for (int i = 0; i <n; ++i) {
            if (table.find(nums[i])!= table.end()) {
                return true;
            }
            table[nums[i]] = 1;
        }
        return false;
    }
};
