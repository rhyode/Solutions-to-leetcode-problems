//1437. Check If All 1's Are at Least Length K Places Away
// simply keep a previous index value and check if the distance with the index at which 1 is got now, if it is less than k

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prev!=-1 && (i-prev-1)<k){
                    return false;
                }
                prev = i;
            }
        }
        return true;

    }
};
