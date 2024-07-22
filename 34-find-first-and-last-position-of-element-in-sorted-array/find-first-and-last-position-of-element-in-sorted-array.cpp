class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n  = nums.size();
        if(n==1 && target==nums[0])     return {0,0};

        map<int,pair<int,int>> mpp;
        int s = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i] != nums[i-1])
            {
                mpp[nums[i-1]] = make_pair(s,i-1);
                s=i;    
            }
            mpp[nums[n - 1]] = make_pair(s, n - 1);
        }
        
        if (mpp.find(target) != mpp.end()) {

        return {mpp[target].first, mpp[target].second};

        }
        return {-1,-1}; 
    }
};