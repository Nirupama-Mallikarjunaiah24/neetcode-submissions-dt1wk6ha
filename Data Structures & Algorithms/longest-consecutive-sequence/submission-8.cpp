class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sol = 0;
        unordered_set<int> hashnum(nums.begin(), nums.end());
        if ( nums.size() == 0) {
            return 0;
        }
        if ( nums.size() == 1) {
            return 1;
        }
        for ( int num: hashnum) {
            if ( hashnum.find(num - 1) == hashnum.end()) {
                // we found the beginning number s
                int streak = 0;
                while (hashnum.find(num) != hashnum.end()) {
                    ++num;
                    ++streak;
                } // keep updating and counting the streak
                // after streak is broken maintain the max
                sol = max (sol, streak);
            }
        }
        return sol;
    }
};

