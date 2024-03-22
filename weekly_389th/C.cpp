class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26);
        for(int i = 0; i < word.size(); i++) {
            cnt[word[i] - 'a']++;
        }
        sort(cnt.begin(), cnt.end());

        int res = 1e9;
        int sub = 0;
        for(auto i: cnt) {
            if(i == 0) {
                continue;
            }

            int up_limit = i + k;
            int add = 0;
            for(auto j: cnt) {
                if(j > up_limit) {
                    add += j - up_limit;
                }
            }

            res = min(res, sub + add);
            sub += i;
        }

        return res;
    }
};
