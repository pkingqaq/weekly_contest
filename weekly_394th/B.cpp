class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        fill(cnt1.begin(), cnt1.end(), -1);
        fill(cnt2.begin(), cnt2.end(), -1);
        int res = 0;
        for(size_t i = 0; i < word.size();i++) {
            char c = word[i];
            //cout << cnt1[i] << " " << cnt2[i] << endl;
            if(c - 'a' >= 0 && c - 'z' <= 0) {
                cnt1[c - 'a'] = i;
            } else {
                if(cnt2[c - 'A'] == -1) {
                    cnt2[c - 'A'] = i;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] != -1 && cnt2[i] != -1 && cnt1[i] < cnt2[i]) {
                res++;
            }
        }
        return res;
    }
};
