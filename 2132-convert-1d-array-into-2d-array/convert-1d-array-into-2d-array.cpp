class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        vector<vector<int>> ans (m, vector<int> (n)) ;
        int k = original.size();
        long long s = m * n;
        vector<vector<int>> tmp;
        if(k != s)   return tmp;

        for(int i = 0;i<k ;i++)
        {
            ans[i/n][i%n] = original[i];
        }
        
        return ans;
    }
};