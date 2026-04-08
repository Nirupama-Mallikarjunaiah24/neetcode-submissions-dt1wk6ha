class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t res = 0;

       for ( int i =0; i < 32; ++i) {
        uint32_t bit = ( n>>i)&1; // extracting the value at ith from n - which is 0 or 1
        res += (bit << (31-i)); // putting it into 31-ith position in the result
       } 

       return res;
    }
};
