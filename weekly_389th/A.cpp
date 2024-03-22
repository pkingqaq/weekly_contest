class Solution {
public:
    bool isSubstringPresent(string s) {
        string ss = s;
        reverse(s.begin(), s.end());

        for(int i = 0; i < ss.size() - 1; i++) {
            if(s.find(ss.substr(i, 2)) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
