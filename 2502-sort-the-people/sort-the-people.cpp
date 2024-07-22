class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mpp;
        int i = 0;
        for(string s : names)
        {
            mpp[heights[i]] = s;
            i++;
        }
        sort(heights.begin(),heights.end(), greater<int>());
        vector<string> ans;
        for(int i = 0 ; i<names.size() ;i++)
        {
            ans.push_back(mpp[heights[i]]);
        }
        return ans;
    }
};