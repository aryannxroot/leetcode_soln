class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        vector<int> check(1001,0);

        for(int i : target)
            check[i]++;

        for(int i : arr)
            check[i]--;
        

        for(int i : check)
            if(i)    
                return false;

        return true;
    }
};