class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> count;
       for ( int n : nums) {
        count[n]++;
       }
/* putting it in min heap to be able to pop the top k elements. heap is sorted by the freq
but also holds the num. But its implementation was complicated for me. had to use the bucket sort now*/
    vector<vector<int>> bucket (nums.size()+1);
    for ( const auto& ele : count) {
        bucket[ele.second].push_back(ele.first);
    }
    vector<int> result;
    for ( int i = bucket.size() -1; i > 0; --i) {
        for ( int n : bucket[i]) {
           result.push_back(n);
           if (result.size() == k)
                return result; 
        }
    }
    return result;
    }
};
