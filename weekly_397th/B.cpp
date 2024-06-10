class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = n - k; i < n; i++) {
            int cur = 0;
            for(int j = i; j >= 0; j -= k) {
                cur += energy[j];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
