class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> temp(n,51);
        int j = 0;
        for(int i = 0 ;i<n;i++)
        {
            if(nums[i] != val)
            {
                temp[j]=nums[i];
                j++;
            }
        }
        sort(temp.begin(),temp.end());
        nums = temp;
        return j;
    }
};