class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long res = 0;
        long long cur = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == c) {
                cur++;
                res+=cur;
            }
        }
        return res;
    }
};
