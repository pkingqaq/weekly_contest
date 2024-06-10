class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        int res = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i <= n - k; i += k) {
            string ss = word.substr(i, k);
            cnt[ss]++;
        }
        int mm = 0;
        for(auto &pair: cnt) {
            mm = max(mm, pair.second);
        }
        return n / k - mm;
    }
};
