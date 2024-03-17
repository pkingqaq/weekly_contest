class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& ca) {
        int n = apple.size();
        int m = ca.size();
        int sum = 0;
        for(int i = 0; i < n;i++) {
            sum+= apple[i];
        }

        int res = 0;
        sort(ca.begin(), ca.end());
        for(int i = m - 1; i >= 0; i--) {
            res++;
            sum -= ca[i];
            if(sum <= 0) {
                return res;
            }
        }
        return res;
    }
};
