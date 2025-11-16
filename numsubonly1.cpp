class Solution {
public:
    int numSub(string s) {
        int totsum = 0;
        int n = s.size();
        int left = 0;
        int right =0;
        int MOD = 1000000007;
        for(right=0;right<n;right++){
            if(s[right]=='0'){
                int len = right-left;
                totsum = (totsum+(1LL*len*(len+1)/2))% MOD;
                left=right+1;
            }
        }
        int len = n - left; 
        if (s[n-1] > 0) {
            totsum = (totsum + (len * (len + 1) / 2)) % MOD;
        }
        return totsum;
    }
};
