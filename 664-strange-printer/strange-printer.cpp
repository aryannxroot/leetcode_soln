class Solution {
private:
    int fun(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) 
        {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        char f = s[i];
        
        int ans = 1 + fun(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) 
        {            
            if (s[k] == f) 
            {                 
                int Ans = fun(i, k - 1, s, dp) + fun(k + 1, j, s, dp);
                ans = min(ans, Ans);
            }
        }
        return dp[i][j] = ans;
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fun(0, n - 1, s, dp);
    }
};