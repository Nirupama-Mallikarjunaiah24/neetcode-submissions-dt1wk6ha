class Solution {
public:
    int getSum(int a, int b) {
        while ( b != 0) {
            int carry = (a&b)<<1; // the carry needs to be added to the next bit to the left so we shift by 1
            a^=b; // has the sum
            b = carry;
        }
        return a;

    }
};
