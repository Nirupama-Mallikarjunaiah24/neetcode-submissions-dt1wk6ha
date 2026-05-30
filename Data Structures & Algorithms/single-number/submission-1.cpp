class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for ( int num: nums) {
            res ^=num;
        }
        return res;
    }
};

// all the repetitions cancel out so only the number that was single is left