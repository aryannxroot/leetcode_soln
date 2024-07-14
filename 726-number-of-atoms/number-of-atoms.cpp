class Solution {
public:
    int now;
    string F;

    int getInt() {
        if(now == F.size() || !isdigit(F[now])) return 1;
        int cur = 0;
        while(now < F.size() && isdigit(F[now])){
            cur = cur * 10 + F[now] - '0';
            now++;
        }
        return cur;
    }

    string getString() {
        string s = string(1, F[now++]);
        while(now < F.size() && islower(F[now])){
            s.push_back(F[now]);
            now++;
        }
        return s;
    }

    map<string, int> getBracket() {
        map<string, int> M;
        while(now < F.size()) {
            if(F[now] == '('){
                now++;
                auto N = getBracket(); 
                
                for(auto x: N){
                    M[x.first] += x.second;
                }
                continue;
            }
            if(F[now] == ')') {
                now++;
                int i = getInt();
               
                for(auto x: M){
                    M[x.first] *= i;
                }
                return M;
            }

            string s = getString(); 
            int x = getInt(); 
            M[s] += x;
        }
        return M;
    }
    string countOfAtoms(string formula) {
        now = 0;
        F = formula;
        auto T = getBracket();
        string s;
        for(auto x: T){
            s += x.first;
            if(x.second > 1) s += to_string(x.second);
        }
        return s;
    }
};