class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int> cnt (26);
        for (char c: s) {
            cnt[c - 'a']++;
        }

        for(int i = 1; i <= n; i++) {
            if(n % i == 0 && check(i, cnt, s)) {
                return i;
            }
        }
        return -1;
    }

    bool check(int len, vector<int> cnt, string s) {
        int n = s.size();
        for(int i = 0 ;i < n; i+= len) {
            vector<int> tmp(26);
            for(int j = 0; j < len; j++) {
                tmp[s[i + j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                if(tmp[j] * (n / len) != cnt[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

