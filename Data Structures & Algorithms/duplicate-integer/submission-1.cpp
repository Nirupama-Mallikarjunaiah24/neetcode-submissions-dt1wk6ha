class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> val; // set only has unique values and unordered since we dont care in whihc order it is saved
        for ( int num: nums) {
            if (val.count(num)) { // already exists
                return true;
            }
            val.insert(num);
            
        }
        return false;
    }
};