class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int max = INT_MIN;
        int idx = 0;
        
        int a = 0;
        int b = k;
        while (a<b){ // get the max of first set
            if (nums[a] > max) {
                    max = nums[a];
                    idx = a;
                }
              //  cout << max <<"max";
            a++;
        }    
        res.push_back(max);

        for ( int i = 1, j = k; j <n; ++i, ++j) {
            // check index is i in the window, if yes then compare with new number
            // if not then calc the new max
            if ( idx < j && idx >= i) {
                if (nums[j] > max) {
                    max = nums[j];
                    idx = j;
                }
            } else {
                int a = i;
                int b = j+1;
                    max = INT_MIN;
                while (a<b){ 
                    if (nums[a] > max) {
                        max = nums[a];
                        idx = a;
                    }
                    a++;
                }
            }
            res.push_back(max);

        }
        return res;
    }
};

/* so i need to compare if the new element is larger than the already existing one 
and also make sure that the larger one was not the element that was left out of the sliding window*/
