class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sz = chalk.size();
        long int total_ch = 0; // sum 

        for(int ch : chalk )    
            total_ch += ch;
            
        k = k%total_ch; // imp line -> reduce the k ,by removing redundant iterations which goes through whole array 
        for(int i = 0; i<sz ;i++)
        {
            if(k<chalk[i])  return i;
            else k -= chalk[i];
        }
        return -1; // dummy return
        
    }
};