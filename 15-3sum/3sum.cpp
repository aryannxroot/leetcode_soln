class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = 0;
        for(int i = 0; i < n ; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int j = i+1 ;
            int k = n-1 ;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                {
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < target)
                    j++;
                else 
                    k--;
            }
        }
        
        return ans;

    }
};