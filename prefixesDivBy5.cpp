//1018. Binary Prefix Divisible By 5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int value = 0;
        int n = nums.size();
        vector<bool> answer(n,false);
        for(int i=0;i<n;i++){
            value = ((value<<1) + nums[i])%5;
            if(value%5==0) answer[i]=true;
        }

        return answer;
    }
};
