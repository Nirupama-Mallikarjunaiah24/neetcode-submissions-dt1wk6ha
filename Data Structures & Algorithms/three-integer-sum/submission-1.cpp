class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // we use the third number as the target as we did in two sum and get the list
        vector<vector<int>> sol;
        int s = nums.size();
        // sort it first to be able to do the two sum problem
        sort(nums.begin(), nums.end());

        for ( int i = 0; i < s; ++i) {
            // if nums are repeated - skip them since it will gkve the same combo
            if (nums[i] == nums[i-1] && i > 0) {
                continue;
            }
            if ( nums[i] > 0) break;
                // target is - nums[i]
                int l = i+1;
                int r = s-1;
                // this handles hwen the nums[i] is a positive number
                while ( l < r) {
                    if (nums[l]+ nums[r] == -nums[i] ) {
                        sol.push_back({nums[i], nums[l], nums[r]});
                        l++; --r;
                        // skip all the same elements as that of nums[l] and nums[r]
                        while ( l < r && nums[l] == nums[l-1]) {
                            l++;
                        }
                    }
                    else if (nums[l]+ nums[r] > -nums[i]) {
                        --r;
                    } else if ( nums[l] + nums[r] < -nums[i]) {
                            l++;
                    }
                }  // becasue if the number is positive and we are moving in asceding order we wont find smaller numbers that add up to the value 
        }
        return sol;
    }
};

// 1 2 3 4