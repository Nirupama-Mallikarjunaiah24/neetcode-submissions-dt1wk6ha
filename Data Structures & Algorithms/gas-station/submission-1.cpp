class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if ( accumulate(gas.begin(), gas.end(),0) < accumulate(cost.begin(),cost.end(),0))
            return -1;
        
        int total = 0;
        int res = 0;

        for ( int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                res = i +1;
            }
        }
        return res;

    }
};

// its not the first positive val element, it needs to be the one that has only positive values after it
// hence why we dont just return i+1 the moment we find a positive value for the diff
