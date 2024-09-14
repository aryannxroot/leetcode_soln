class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0,cnt = 0;
        int maxb = *max_element(nums.begin(),nums.end());

        for(int i = 0;i<n;i++)
        {
            if(nums[i]==maxb)
                cnt++;
            else{
                ans = max(ans,cnt);
                cnt = 0;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};