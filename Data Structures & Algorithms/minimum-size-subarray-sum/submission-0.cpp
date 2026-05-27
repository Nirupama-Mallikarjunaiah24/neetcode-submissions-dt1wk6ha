class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int cursum = 0;
        int minlen = nums.size();
        for ( int j = 0; j < nums.size(); ++j) {
            cursum += nums[j];
            if(cursum >= target) {
                minlen = min ( minlen, j-i+1);
                while (cursum >=target) {
                    cursum -= nums[i];
                    i++;
                }
            }
        }

        return minlen;
    }
};