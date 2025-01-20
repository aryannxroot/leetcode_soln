class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int s = arr.size();
        int m = mat.size(), n = mat[0].size();
        vector<int>rowCount(m),colCount(n);
        unordered_map<int, pair<int,int>> mpp;
        for(int r = 0; r<m; r++)
        {
            for(int c = 0; c<n; c++)
            {
                int val = mat[r][c];
                mpp[val] = {r,c};
            }
        }
        
        for(int i = 0 ; i<s; i++)
        {
            int target = arr[i];
            auto [r,c] = mpp[target];
            rowCount[r]++;
            colCount[c]++;

            if (rowCount[r] == n || colCount[c] == m) {
                return i;
            }
        }
        return -1;
    }
};