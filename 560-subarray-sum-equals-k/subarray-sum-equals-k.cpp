#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixSums;
        prefixSums[0] = 1; 
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;
            int complement = currentSum - k;

            if (prefixSums.find(complement) != prefixSums.end()) {
                count += prefixSums[complement];
            }

            prefixSums[currentSum]++;
        }

        return count;
    }
};
