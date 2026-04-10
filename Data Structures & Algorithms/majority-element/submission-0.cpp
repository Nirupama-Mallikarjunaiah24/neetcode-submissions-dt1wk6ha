class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj = 0;

        for(int num: nums) {
            if (num == maj) {
                count++;
            } else if (count == 0) {
                maj = num;
                count ++;
            } else {
                count --;
            }
        }

        count = 0;
        for (int num:nums) {
            if (num == maj) {
                count++;
            }
        }
        if ( count > (nums.size()/2)) {
            return maj;
        }
    }
};