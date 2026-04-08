#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       std::unordered_map<int,int>table;
       int n = nums.size();
       int diff;

       for (int i = 0; i< n;++i) {
            diff = target - nums[i];
            if (table.find(diff) != table.end()) {
                return {table[diff], i};
            }
            table[nums[i]] = i;
       } 
       return {};
    }
};
/* storing the i value so i can just return that instead of figuring that out again 
this is to avoid two for loops though technically they both have same complexity*/
