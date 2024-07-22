class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for(int i: nums)    mpp[i]++;
        for(auto it = mpp.begin() ; it!=mpp.end() ; it++)
        {
            if(it->second == 1) return it->first;
        }
        return 0;
    }
};