class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> res(n);
        for(int i = 0;i < n; i++) {
            string str = arr[i];
            string cur = "";
            // cout << i << endl;
            for(int size = 1; size <= str.size() && cur == ""; size++) {
                for(int j = 0; j + size - 1 < str.size(); j++) {
                    string substr = str.substr(j, size);
                    // cout << substr << endl;
                    if(!check(substr, arr, i) && (cur == "" || cur > substr)) {
                        // cout << substr + "111" << endl;
                        cur = substr;
                    }
                }
            }
            res[i] = cur;
        }
        return res;
    }

    bool check(string strs, vector<string> arr, int index) {
        for(int i = 0; i < arr.size(); i++) {
            if(i == index) {
                continue;
            }
            if(arr[i].find(strs) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
