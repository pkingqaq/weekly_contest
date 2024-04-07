class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 1;
        for(int i = 0, j = 0; j < n; j++) {
            if(j == 0) {
                continue;
            }
            if(nums[j] == nums[j - 1]) {
                i = j;
            }
            res += j - i + 1;
        }
        return res;
    }
};
