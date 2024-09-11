class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a>0 || b>0 || c>0)
        {
            if(c%2 == 0)
            {
                if(a%2 == 1)    cnt++;
                if(b%2 == 1)    cnt++;
            }else{
                if(a%2 == 0 && b%2 == 0)    cnt++;
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return cnt;

    }
};