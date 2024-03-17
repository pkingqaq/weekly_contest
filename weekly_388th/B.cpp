class Solution {
public:
    long long maximumHappinessSum(vector<int>& hps, int k) {
        long long res = 0;
        sort(hps.begin(), hps.end(), greater<>());
        for(int i = 0; i < k; i++) {
            res += max(0, hps[i] - i);
        }
        return res;
    }
};
