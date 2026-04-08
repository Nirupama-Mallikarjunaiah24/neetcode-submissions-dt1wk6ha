class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int,int>> vehicle;
        vector<double> stk;
        for (int i = 0; i < position.size(); ++i) {
            vehicle.push_back({position[i], speed[i]});
        }

        std::sort(vehicle.rbegin(), vehicle.rend());

        for ( int i = 0; i < position.size(); ++i) {
            stk.push_back((double)(target - vehicle[i].first)/ vehicle[i].second);
            if ( stk.size() >=2 && stk.back() <= stk[stk.size()-2])
            {stk.pop_back();}
        }
        return stk.size();
    }
};
