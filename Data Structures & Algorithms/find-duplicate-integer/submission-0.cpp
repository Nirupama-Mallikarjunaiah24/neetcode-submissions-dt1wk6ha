class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow =0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow)
            break;
        } 
        int head = 0;
        while ( true) {
            slow = nums[slow];
            head = nums[head];
            if(slow == head) {
                return slow;
            }
        }
    }
};
