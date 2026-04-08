class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for( int st: stones) {
            maxh.push(st);
        }
        while(maxh.size() > 1) {
            int st1 = maxh.top(); maxh.pop();
            int st2 = maxh.top(); maxh.pop();
            if (st2 <st1) {
                maxh.push(st1-st2);
            }
        }
        maxh.push(0);
        return maxh.top();
    }
};
