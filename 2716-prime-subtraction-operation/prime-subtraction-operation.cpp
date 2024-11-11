class Solution {
public:
    bool checkPrime(int n)
    {
        for(int i = 2 ; i*i <= n; i++)
        {
            if(n%i == 0)
                return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n; i++)
        {
            int bound;

            if(i == 0)  bound = nums[i];
            else bound = nums[i] - nums[i-1];

            if(bound <= 0)  return false;

            int largestPrime = 0;
            for(int j = bound - 1; j >= 2; j--)
            {
                if(checkPrime(j))   
                {
                    largestPrime = j;
                    break;
                }
            }
            
            nums[i] -= largestPrime;
        }
        return true;
    }
};