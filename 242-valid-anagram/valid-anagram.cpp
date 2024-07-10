class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size()!=t.size())return false;
        long long sum_s=1,sum_t=1;

        for(int i=0;i<s.size();i++){
            sum_s+=s[i]*((s[i]+1)/2);
            sum_t+=t[i]*((t[i]+1)/2);
        }

        return sum_s == sum_t;
    }
};