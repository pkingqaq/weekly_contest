class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t;
        for(int i = 0; i < n; i++) {
            int d = dis(s[i] - 'a', 0);
            cout << d << endl;
            if(d <= k) {
                k -= d;
                t.push_back('a');
            } else {
                t.push_back(s[i] - k);
                k = 0;
            }
        }
        return t;
    }

    int dis(char a, char b) {
        return min((a - b + 26) % 26, (b - a + 26) % 26);
    }
};
