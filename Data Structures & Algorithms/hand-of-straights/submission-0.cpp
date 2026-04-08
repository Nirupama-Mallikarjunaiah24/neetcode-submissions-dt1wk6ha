class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize !=0)
            return false;
        map<int,int> count;
        for ( int num:hand) count[num]++;

        for( auto it = count.begin(); it != count.end(); ++it) {
            int val = it->first;
            int freq = it->second;
            if(freq == 0) continue;

            for ( int i = 0; i < groupSize; ++i) {
                if (!count.count(val + i) || count[val + i] < freq)
                    return false;
                count[val+i] -= freq;
            }
        }
        return true;
    }
};
