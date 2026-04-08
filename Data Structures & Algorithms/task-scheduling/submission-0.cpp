class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for( char c: tasks) {
            freq[c-'A']++;
        }

        priority_queue<int> maxh;
        for( int c: freq){
            if (c> 0) {
                maxh.push(c);
            }
        }

        int time = 0;
        queue<pair<int,int>> q;
        while( !maxh.empty() || !q.empty()) {
            time++;

            if( maxh.empty()) { // if all tasks are in cooldown just jump to the time that he queue is reayd to execute
                time = q.front().second;
            } else { // get the highest freq letter and reduce cnt and put to cooldown
                int cnt = maxh.top()-1;
                maxh.pop();
                if ( cnt> 0) {
                    q.push({cnt,time+n});
                }
            }
            if (!q.empty() && q.front().second == time) { // the parts that are done with cooldown and can be used net are added back to the heap
                maxh.push(q.front().first);
                q.pop();
            }

        }
        return time;
    }
};
