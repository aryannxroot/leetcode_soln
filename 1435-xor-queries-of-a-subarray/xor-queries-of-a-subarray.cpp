class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto query : queries)
        {
            int l = query[0];
            int r = query[1];
            int cnt = arr[l];
            l++;
            while(l<=r)
            {
                cnt ^= arr[l];
                l++;
            }
            ans.push_back(cnt);
        }
        return ans ;
    }
};