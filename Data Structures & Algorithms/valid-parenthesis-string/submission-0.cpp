class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stpara;
        stack<int> ststar;

        for (int i = 0 ; i< s.size(); ++i) {
            if (s[i] == '(')
                stpara.push(i);
            else if (s[i] == '*')
                ststar.push(i);
            else { // )
                if ( !stpara.empty())
                    stpara.pop();
                else if (!ststar.empty())
                    ststar.pop();
                else
                    return false;
            }
        }

        while (!stpara.empty() && !ststar.empty()) {
            if (stpara.top() < ststar.top()) {
                stpara.pop(); ststar.pop();
            } else {
                return false;
            }

        }

        if (stpara.empty())
            return true;
        else
            return false;
    }
};
