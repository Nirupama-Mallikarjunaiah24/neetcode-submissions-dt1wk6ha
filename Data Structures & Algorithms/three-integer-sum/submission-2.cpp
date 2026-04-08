class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        unordered_map<int,int> count;
        for (int x : nums) count[x]++;

        for (int i = 0; i < n; ++i) {
            // skip duplicate i BEFORE consuming it
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // mark nums[i] as used for this i
            count[nums[i]]--;

            for (int j = i + 1; j < n; ++j) {
                // skip duplicate j BEFORE consuming it
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                // mark nums[j] as used for this (i,j)
                count[nums[j]]--;

                int target = -(nums[i] + nums[j]);
                // FIX: Ensure target is >= nums[j] to enforce a sorted order and avoid duplicates
                if (target >= nums[j]) {
                    auto it = count.find(target);
                    if (it != count.end() && it->second > 0) {
                        res.push_back({nums[i], nums[j], target});
                    }
                }

                // restore nums[j] for next j
                count[nums[j]]++;
            }

            // restore nums[i] before next i
            count[nums[i]]++;
        }

        return res;
    }
};