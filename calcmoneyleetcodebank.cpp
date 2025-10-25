// 1716. Calculate Money in Leetcode Bank

class Solution {
public:
    int totalMoney(int n) {
        int w = n/7;
        int m = n%7;
        return 28*w + 7*(w-1)*(w)/2 + m*(2*w+m+1)/2;
    }
};
