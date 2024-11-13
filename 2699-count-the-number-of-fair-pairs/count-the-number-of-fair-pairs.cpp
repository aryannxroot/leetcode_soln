class Solution {
public:
    long long bound(vector<int>&nums, int low, int high, int elem)
    {
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] >= elem)
                high = mid -1;
            else
                low = mid + 1;
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            int low = bound(nums, i+1, nums.size() - 1, lower - nums[i]);
            int high = bound(nums, i+1, nums.size() - 1, upper - nums[i] + 1);

            ans += 1LL*(high - low);
        }
        return ans;
    }
};