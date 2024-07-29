class Solution {
public:
    int numTeams(vector<int>& ra) {
        int n = ra.size();
        int ans = 0;
        for(int i = 1 ; i<n-1 ;i++){
            vector<int> l(2,0);
            vector<int> r(2,0);
            
            for(int j =0;j<i;j++)
                l[ra[j] < ra[i]]++;

            for(int k=i+1 ; k<n ;k++)
                r[ra[k] < ra[i]]++;
            
            ans += l[0]*r[1] + l[1]*r[0];
        }
        return ans;
    }
};