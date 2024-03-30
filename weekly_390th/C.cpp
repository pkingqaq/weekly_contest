class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<int, long long> cnt;
        vector<long long> res(n);
        multiset<long long>ms;

        for(int i =0; i < n;i++) {
            auto it = ms.find(cnt[nums[i]]);
            if( it != ms.end()) {
                ms.erase(it);
            }
            cnt[nums[i]] += freq[i];
            ms.insert(cnt[nums[i]]);
            res[i] = *ms.rbegin();
        }
        return res;
    }
};

// 这里的ms.erase(it)很有讲究，it会只删迭代的那一个数字，如果是ms.erase(nums[i]])会直接删除所有符合这个值的element
