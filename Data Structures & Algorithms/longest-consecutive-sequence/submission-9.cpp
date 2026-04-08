class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash (nums.begin(), nums.end());
        int longest = 0;
        if (nums.size()<=0)
            return longest;
        
        for ( int i = 0; i < nums.size();++i) {
            int currNum = nums[i];
                int count = 1;

                while (hash.find(currNum + 1) != hash.end()) { // search for value!!!
                    currNum++;
                    count++;
                }
            longest = max(longest, count);
        }
    

    return longest; }
};

//s.find(target) != s.end()