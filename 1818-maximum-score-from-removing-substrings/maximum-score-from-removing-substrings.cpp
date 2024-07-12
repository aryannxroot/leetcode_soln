class Solution {
public:
    int maximumGain(string s, int x, int y) {
    string p1, p2;
    int p1Pts, p2Pts;

    if (x > y) {
        p1 = "ab";
        p2 = "ba";
        p1Pts = x;
        p2Pts = y;
    } else {
        p1 = "ba";
        p2 = "ab";
        p1Pts = y;
        p2Pts = x;
    }

    auto removePairs = [](string &s, const string &pat, int pts) {
        stack<char> st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == pat[0] && c == pat[1]) {
                st.pop();
                score += pts;
            } else {
                st.push(c);
            }
        }

        string rem;
        while (!st.empty()) {
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        s = rem;

        return score;
    };

    int totalScore = 0;
    totalScore += removePairs(s, p1, p1Pts);
    totalScore += removePairs(s, p2, p2Pts);

    return totalScore;
    }
};