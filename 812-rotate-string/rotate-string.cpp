class Solution {
public:
    string rot_1(string s)
    {
        int n = s.size();
        int i = 1;
        string news = "";
        while(i<n)
        {
            news += s[i];
            i++;
        }
        news += s[0];
        return news;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())   return false;
        if(s==goal) return true;
        int n = s.size();
        while(n--)
        {
            s = rot_1(s);
            if(s==goal) return true;
        }
        return false;
    }
};