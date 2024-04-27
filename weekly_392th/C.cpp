class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();
        int mid = n / 2;
        if(nums[mid] > k) {
            for(int i = 0; i <= mid; i++) {
                if(nums[i] > k) {
                    res += nums[i] - k;
                }
            }
        } else {
            for(int i = mid; i < n; i++) {
                if(nums[i] < k) {
                    res += k - nums[i];
                }
            }
        }
        return res;
    }
};
