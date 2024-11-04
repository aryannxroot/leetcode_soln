class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        while(i<word.size())
        {
            int cnt = 1;
            while(word[i] == word[i+1] && cnt <9)  {
                cnt++;
                i++;
            }
            comp += to_string(cnt)+word[i];
            i++;
        }   
        return comp;
    }
};