class Solution {
public:
    vector<vector<int>> generate(int numRows) {

    vector<vector<int>>ans;

    for(int i=0 ; i<numRows ; i++)
    {
        vector<int> subans(i+1);
        for(int j = 0; j<=i ;j++)
        {
            if(j==0 || j==i)
            subans[j] = 1;
            else
            {
                subans[j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        ans.push_back(subans);
    }
        
    return ans;

    }
};