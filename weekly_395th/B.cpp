//brute force
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int ans = 1e9;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> vec;
                for(int k = 0; k < n; k++) {
                    if(k != i && k != j) {
                        vec.push_back(nums1[k]);
                    }
                }
                if(check(vec,nums2)) {
                    ans = min(ans, nums2[0] - vec[0]);
                }
            }
        }
        return ans;
    }
    bool check(vector<int> nums1, vector<int> nums2) {
        int m = nums2.size();
        int d = nums2[0] - nums1[0];
        for (int i = 0; i < m; i++) {
            if(nums1[i] + d != nums2[i]) {
                return false;
            }
        }
        return true;
    }
};

//找最小子序列
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int ans = 1e9;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> vec;
                for(int k = 0; k < n; k++) {
                    if(k != i && k != j) {
                        vec.push_back(nums1[k]);
                    }
                }
                if(check(vec,nums2)) {
                    ans = min(ans, nums2[0] - vec[0]);
                }
            }
        }
        return ans;
    }
    bool check(vector<int> nums1, vector<int> nums2) {
        int m = nums2.size();
        int d = nums2[0] - nums1[0];
        for (int i = 0; i < m; i++) {
            if(nums1[i] + d != nums2[i]) {
                return false;
            }
        }
        return true;
    }
};
