class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int res = 0;
        int num = x;
        while(num > 0) {
            res += num % 10;
            num /= 10;
        }
        if(x % res == 0) {
            return res;
        } else {
            return -1;
        }
    }
};
