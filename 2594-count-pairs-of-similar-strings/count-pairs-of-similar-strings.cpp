class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i = 0 ; i<n;i++)
        {
            set<char>s1;
            for(auto it: words[i])  s1.insert(it);
            string tmp = "";
            for(auto it : s1)
            {
                tmp += it;
            }
            words[i] = tmp;
        }

        for(int i = 0;i<n-1;i++)
        {
            // cout<<"words["<<i<<"] :"<<words[i]<<endl;
            for(int j = i+1;j<n;j++)
            {
                if(words[i] == words[j])
                    cnt++;
                // cout<<"\twords["<<j<<"] :"<<words[j]<<" cnt: "<<cnt<<endl;
            }
        }
        
        return cnt;
    }
};