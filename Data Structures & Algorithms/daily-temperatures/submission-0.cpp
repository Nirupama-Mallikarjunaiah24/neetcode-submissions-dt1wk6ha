class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        int n = temperatures.size();
        vector<int> res (temperatures.size(),0);

        for ( int i = 0; i < n; ++i) {
                while(!stack.empty() && temperatures[i] > stack.top().first){
                    pair<int,int> element = stack.top();
                    res[element.second] = i - element.second;
                    // calc
                    stack.pop();
                }
                stack.push({temperatures[i],i});
        }
        return res;
    }
};
// if i track the elements in the stack then i can judge
// geniusss i can store both values using pair!!