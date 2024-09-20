class Solution {
public:
    string shortestPalindrome(string s) {
        string revS = s;
        reverse(revS.begin(),revS.end());

        for(int i = 0 ; i<s.size();i++)
        {
            if (!memcmp(s.c_str(), revS.c_str() + i, s.size() - i)) {
                return revS.substr(0, i) + s;
            }
        }
        return revS + s;
    }
};