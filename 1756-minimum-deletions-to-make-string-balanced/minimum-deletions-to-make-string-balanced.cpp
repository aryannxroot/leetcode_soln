class Solution {
public:
    int minimumDeletions(string s) {
       int cntb = 0;
       int ans = 0;

       for(char c : s)
       {
        if(c == 'b')    cntb++;
        else    ans = min(ans + 1, cntb);
       }
       return ans;
    }
};