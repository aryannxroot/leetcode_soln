class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,char>m;
        map<char,int>m1,m2;

        for(auto &i:s)m1[i]++;
        for(auto &i:t)m2[i]++;

        vector<int>v1,v2;
        for(auto &i:m1)v1.push_back(i.second);
        for(auto &i:m2)v2.push_back(i.second);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        if(v1!=v2)return false;
        for(int i=0;i<s.size();i++)m[s[i]]=t[i];

        for(int i=0;i<s.size();i++){
        if(m[s[i]]!=t[i])return false;
        }

        return true;
    }
};