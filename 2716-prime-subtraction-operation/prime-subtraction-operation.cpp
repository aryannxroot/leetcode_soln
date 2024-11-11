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

        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> prevPrime(maxEle + 1, 0);

        for(int i = 2; i< maxEle ; i++)
        {
            if(checkPrime(i))   prevPrime[i] = i;
            else    prevPrime[i] = prevPrime[i-1];
        }

        for(int i = 0 ; i<n; i++)
        {
            int bound;

            if(i == 0)  bound = nums[i];
            else bound = nums[i] - nums[i-1];

            if(bound <= 0)  return false;

            int largestPrime = prevPrime[bound - 1];
            nums[i] -= largestPrime;
        }
        return true;
    }
};