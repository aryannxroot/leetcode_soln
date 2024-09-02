class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sz = chalk.size();
        long long total_ch = 0;

        for(int ch : chalk )    
            total_ch += ch;

        k %= total_ch;

        for(int i = 0; i<sz ;i++)
        {
            if(k<chalk[i])  return i;
            k -= chalk[i];
        }

        return -1;
        
    }
};