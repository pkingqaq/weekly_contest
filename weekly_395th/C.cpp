class Solution {
public:
    long long minEnd(int n, int x) {
        n = n - 1;
        long long ans = 0;
        // 10001000
        // 111101
        // -> 11111101

        // 10001000
        // 1111101
        // -> 111111101
        vector<int> vec;
        for(;x > 0;x >>= 1) {
            vec.push_back(x & 1);
        }
        int idx = 0;
        for(;n > 0; n >>= 1) {
            while(idx < vec.size() && vec[idx] == 1) {
                idx++;
            }   
            if(idx == vec.size()) {
                vec.push_back(n & 1);
            } else {
                vec[idx] = (n & 1);
            }
            idx++;
        }
        for(int i = vec.size() - 1; i >= 0; i--) {
            ans *= 2;
            ans += vec[i];
        }
        return ans;
    }
};
