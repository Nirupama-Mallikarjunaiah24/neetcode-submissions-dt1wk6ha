class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        std::stack<std::pair<int,int>> st;

        for (int i = 0; i < temperatures.size(); ++i) {
                while (!st.empty() && temperatures[i]> st.top().first) {
                        auto diff = st.top();
                        st.pop();
                        res[diff.second] = i- diff.second;
                }
            st.push({temperatures[i],i});
        }
        return res;
    }
};
