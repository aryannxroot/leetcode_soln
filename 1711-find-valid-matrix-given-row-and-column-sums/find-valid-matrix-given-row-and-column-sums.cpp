class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n,0));

        for(int i = 0; i<m ;i++)
        {
            for(int j =0 ; j<n; j++)
            {
                int el = min(rowSum[i],colSum[j]);
                ans[i][j] = el;
                rowSum[i] -= el;
                colSum[j] -= el;
            }
        }
        return ans;
    }
};