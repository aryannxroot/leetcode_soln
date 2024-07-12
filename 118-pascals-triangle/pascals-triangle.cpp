class Solution {
public:

    vector<int> generateRow (int row)
    {
        vector<int> ans_row;
        ans_row.push_back(1);
        long long res = 1;
        for(int col = 1; col < row ; col++)
        {
            res = res * (row-col);
            res = res / col ;
            ans_row.push_back(res);
        }
        return ans_row;
    }

    vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans;
    for(int i=1 ; i<=numRows ; i++)
    {
        ans.push_back(generateRow(i));
    }
        
    return ans;

    }
};