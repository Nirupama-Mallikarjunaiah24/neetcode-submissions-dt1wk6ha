class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int cursum = 0;
        int i;

        for (int j = 0; j < arr.size(); ++j) {
            cursum += arr[j];

            if (j-i+1 == k) {
                if (cursum >= threshold) {
                    count++;
                }
                cursum -= arr[i];
                i++;
            }
        }

        return count
    }
};