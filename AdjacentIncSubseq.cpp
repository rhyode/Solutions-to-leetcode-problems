//3349. Adjacent Increasing Subarrays Detection I

class Solution {
public:

    bool isincreasing(vector<int>& nums, int start, int end){
        for(int i=start+1;i<end;i++){
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<=n-2*k;i++){
            bool c1 = isincreasing(nums,i,i+k);
            bool c2 = isincreasing(nums,i+k,i+2*k);
            if(c1==true && c2==true) return true;
        }
        return false;
    }
};
