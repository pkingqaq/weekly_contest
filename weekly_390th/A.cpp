class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>cnt(26);
        int res = 0;
        int l = 0; int r = 0;
        while(r < s.size()) {
            cnt[s[r] - 'a']++;
            while(cnt[s[r] - 'a'] > 2) {
                cnt[s[l] - 'a']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
