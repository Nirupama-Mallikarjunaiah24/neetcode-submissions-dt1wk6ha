class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorall = 0;
        for ( int & num: nums) {
            xorall ^=num;
        }

        int differ = 1;
        while ((xorall & differ) == 0) {
            differ <<=1;
        }

        int a = 0, b = 0;

        for ( int &num : nums) {
            if (num & differ) {
                a ^=num;
            } else {
                b ^=num;
            }
        }

        return {a,b};
    }
};

