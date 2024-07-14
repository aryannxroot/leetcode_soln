class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = 0;
        set<vector<int>> st; 
        for(int i = 0; i < n ; i++)
        {
            int j = i+1 ;
            int k = n-1 ;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < target)
                    j++;
                else 
                    k--;
            }
        }
        
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;

    }
};