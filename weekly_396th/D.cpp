class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int c1, int c2) {
        const int MOD = 1e9 + 7;
        long long n = nums.size();
        auto [m, M] = ranges::minmax(nums);
        long long base = n * M - reduce(nums.begin(), nums.end(), 0LL);
        if (n <= 2 || c1 * 2 <= c2) {
            return base * c1 % MOD;
        }

        auto f = [&](int x) -> long long {
            long long s = base + (x - M) * n;
            int d = x - m;
            if (d * 2 <= s) {
                return s / 2 * c2 + s % 2 * c1;
            }
            return (s - d) * c2 + (d * 2 - s) * c1;
        };

        int i = (n * M - m * 2 - base + n - 3) / (n - 2);
        return i <= M ? min(f(M), f(M + 1)) % MOD :
               min({f(M), f(i - 1), f(i), f(i + 1)}) % MOD;
    }
};
