class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        map<string,int> mpp;
        vector<string> ans;

        for(string s : arr)
        {
            mpp[s]++;
        }
        
        for(string s : arr)
        {
            if(mpp[s] == 1)
                ans.push_back(s); 
        }

        return ans.size() >= k ? ans[k-1] : "" ; 

    }
};