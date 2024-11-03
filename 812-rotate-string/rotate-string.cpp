class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string conc = s + s;
        for(int i = 0 ; i<s.size();i++)
        {
            if(conc.substr(i,s.size()) == goal)
                return true;
        }
        return false;
    }
};