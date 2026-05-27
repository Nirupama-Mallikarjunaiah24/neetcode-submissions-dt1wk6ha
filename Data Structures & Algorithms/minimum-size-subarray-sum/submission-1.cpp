class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int cursum = 0;
        int minlen = nums.size()+1;
        for ( int j = 0; j < nums.size(); ++j) {
            cursum += nums[j];
                while (cursum >=target) {
                    cursum -= nums[i];
                    minlen = min ( minlen, j-i+1);
                    i++;
                }
        }

        return minlen == nums.size()+1? 0 : minlen;
    }
};