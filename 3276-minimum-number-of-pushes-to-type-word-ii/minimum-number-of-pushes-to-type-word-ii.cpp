class Solution {
public:
    int minimumPushes(string word) {
        vector<int> fr(26,0);

        for(char c: word) 
            fr[c-'a']++;

        sort(fr.begin(), fr.end());
    
        int s=25, ans=0;
        for(; s>=0 && fr[s]!=0; s--)
        {
            ans += fr[s]*( (25-s)/8+1 );    
        }

        return ans;
    }
};