class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a = nums1;
        vector<int> b = nums2;
        int half = (a.size() + b.size()+1)/2;

        if ( a.size() > b.size()) {
            swap(a,b);
        } // a needs to be smaller
        
        int l = 0, r = a.size();
        while (l <=r) {
            int mid = l + (r-l)/2;
            int j = half - mid;

            int aleft = (mid > 0) ? a[mid-1] : INT_MIN;
            int aright = (mid < a.size()) ? a[mid] : INT_MAX;
            int bleft = (j > 0) ? b[j-1]: INT_MIN;
            int bright = (j < b.size()) ? b[j] : INT_MAX;

            if (aleft <= bright && bleft <= aright) { // partition is correct
                // odd and even 
                if ((a.size()+b.size())%2 == 0)
                    return ((min(aright,bright) + max(bleft,aleft))/2.0);
                return max(aleft,bleft);    
            } else if (aleft > bright) {
                r = mid -1;
            } else {
                l = mid+1;
            }
        }
        return -1;
    }
};
