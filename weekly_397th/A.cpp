class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> cnt(26);
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a'] = i;
        }

        int res = 0;
        for(int i = 0; i < t.size(); i++) {
            res += abs(cnt[t[i] - 'a'] - i);
        }
        return res;
    }
};
