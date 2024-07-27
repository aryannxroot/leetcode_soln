class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
     vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        long long n = o.size();
        for(long long i=0; i<n; i++){
            dist[o[i]-'a'][c[i]-'a'] = min(dist[o[i]-'a'][c[i]-'a']*1LL, cost[i]*1LL);
        }
        for(long long i=0; i<26; i++) dist[i][i] = 0;

        for(long long k=0; k<26; k++){
            for(long long i=0; i<26; i++){
                for(long long j=0; j<26; j++){
                    if(dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j]*1LL, (dist[i][k]+dist[k][j])*1LL);
                }
            }
        }
        long long ans=0;
        for(long long i=0; i<s.size(); i++){
            if(dist[s[i]-'a'][t[i]-'a'] == LLONG_MAX) return -1;
            ans+=(dist[s[i]-'a'][t[i]-'a']);
        }
        return ans>=LLONG_MAX?-1:ans;
    }
};