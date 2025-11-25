//1015. Smallest Integer Divisible by K

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        int n = 1;
        int digit = 1;
        while(n%k!=0){
            n= ((n*10)+1)%k;
            digit++;
        } 
        return digit;
        }
};
