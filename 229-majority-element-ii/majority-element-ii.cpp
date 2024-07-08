class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> results;
        int n = nums.size();
        unordered_map<int, int>arr; 
        int mint = (n / 3) < 1 ? 0 : n/3 ;
        
        for(int i = 0 ; i<n ; i++)
        {
            arr[nums[i]] += 1;
        }

        for(auto it = arr.begin(); it != arr.end() ; it++ )
        {
            if(it->second > mint)
            {
                results.push_back(it->first);
            }
        }
        return results;
    }
};