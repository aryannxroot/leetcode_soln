class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;

    for(int row = 0; row < matrix.size(); row++) {
        int minInRow = matrix[row][0];
        int minColumnIndex = 0;

        for(int col = 1; col < matrix[row].size(); col++) {
            if(matrix[row][col] < minInRow) {
                minInRow = matrix[row][col];
                minColumnIndex = col;
            }
        }

        bool isLucky = true;
        for(int r = 0; r < matrix.size(); r++) {
            if(matrix[r][minColumnIndex] > minInRow) {
                isLucky = false;
                break;
            }
        }

        if(isLucky) {
            ans.push_back(minInRow);
        }
    }

    return ans;
    }
};