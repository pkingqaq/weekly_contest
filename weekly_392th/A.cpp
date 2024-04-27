class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        int cur = 1;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] > nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            res = max(res, cur);
        }

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] < nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};
