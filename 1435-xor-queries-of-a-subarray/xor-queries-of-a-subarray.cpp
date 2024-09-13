class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;

        for(int i = 1;i<arr.size();i++)
        {
            arr[i] ^= arr[i-1];
        }

        for(auto query : queries)
        {
            if(query[0]>0)  ans.push_back(arr[query[0]-1]^arr[query[1]]);
            else    ans.push_back(arr[query[1]]);
        }
        return ans ;
    }
};
