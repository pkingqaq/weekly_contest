class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt(26);
        int ans = 0;
        for(auto c : word) {
            if(c - 'a' >= 0 && c - 'z' <= 0) {
                cnt[c- 'a'] |= 1;
            } else {
                cnt[c - 'A'] |= 2;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 3) {
                ans++;
            }
        }
        return ans;
    }
};
