class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char, int> count_s, count_t;

    for(char c : s) {
        count_s[c]++;
    }
    for(char c : t) {
        count_t[c]++;
    }
    
    return count_s == count_t;
    }
};