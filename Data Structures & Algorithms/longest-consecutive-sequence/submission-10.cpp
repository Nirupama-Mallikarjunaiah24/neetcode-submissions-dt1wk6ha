class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numset;
        for( int i = 0; i < nums.size(); ++i) {
            numset.insert(nums[i]);
        }

        for( int i = 0; i < nums.size();++i) {
            int length = 0;
            if(numset.find(nums[i]-1) == numset.end()) {
                length = 1;
                int next = nums[i]+1;
                while (numset.find(next) != numset.end()) {
                    length++;
                    next++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};
