class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, cursum = 0;
        unordered_map<int,int> prefix;
        prefix[0] = 1; // if the first index is itself the value of k

        for (int num:nums) {
            cursum+=num;
            int diff = cursum - k;
            res += prefix[diff];
            prefix[cursum]++;
        }

        return res;
    }
};