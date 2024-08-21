class Solution {
private:
    int fun(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) 
        {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        char firstLetter = s[i];
        
        int answer = 1 + fun(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) 
        {            
            if (s[k] == firstLetter) 
            {                 
                int betterAnswer = fun(i, k - 1, s, dp) + fun(k + 1, j, s, dp);
                answer = min(answer, betterAnswer);
            }
        }
        return dp[i][j] = answer;
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fun(0, n - 1, s, dp);
    }
};