class Solution {
public:
    int mySqrt(int x) {
        long long ans = 1;
        long long sq = ans*ans;
        while(true)
        {
            if(sq == x) break;
            if(sq>x)    return ans-1;
            ans++;
            sq = ans*ans;
        }
        return (int)ans;
    }
};