class Solution {
public:
    bool isValid(string word) {
        set<char> ss = {'a','e','i','o','u','A','E','I','O','U'};
        if(word.size() < 3) {
            return false;
        }

        bool isVowels = false;
        bool isConso = false;
        for (char c: word) {
            if((c - 'a' >= 0 && c - 'z' <= 0) || (c - 'A' >= 0 && c - 'Z' <= 0)) {
                if(ss.find(c) != ss.end()) {
                    isVowels = true;
                } else {
                    isConso = true;
                }
            } else if (c - '0' >= 0 && c - '9' <= 0) {
                continue;
            } else {
                return false;
            }
        }
        return isVowels && isConso;
    }
};
