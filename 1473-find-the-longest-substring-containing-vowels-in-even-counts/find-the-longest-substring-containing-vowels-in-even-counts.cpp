class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int>mpp;
        mpp[0] = -1;

        int mask = 0;
        int max_l = 0;

        for(int i = 0;i<n;i++)
        {
            if(s[i]=='a'){
                mask ^= 1 << 0;
            }else if(s[i] == 'e'){
                mask ^= 1 << 1;
            }else if(s[i] == 'i'){
                mask ^= 1 << 2;
            }else if(s[i] == 'o'){
                mask ^= 1 << 3;
            }else if(s[i] == 'u'){
                mask ^= 1 << 4;
            }

            if(mpp.find(mask) != mpp.end()){
                max_l = max(max_l, i - mpp[mask]);
            }else{
                mpp[mask] = i;
            }
        }
        return max_l;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();