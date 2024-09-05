class Solution {

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot = 0;
        for ( int i : rolls)
            tot += i;
        
        int res = ((rolls.size() + n) * mean ) - tot;

        if(res < n || res > 6*n)   return {};

        int q = res / n ;
        int r = res % n ;
        vector<int> ans (n-r,q);
        for(int i = 0; i<r ; i++)
        {
            ans.push_back(q+1);
        }
        return ans;
    }
};