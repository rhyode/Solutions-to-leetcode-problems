
//3350. Adjacent Increasing Subarrays Detection II
class Solution{
public:
int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ninc(n);
        ninc[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ninc[i] = ninc[i+1] + 1;
            }
            else{
                ninc[i] = 1;
            }
        }

        int ans = 0;    
        int l = 0;
        int r = n/2;

        while(l <= r){  
            int mid = l + (r - l) / 2;

            bool possible = false;
            for(int i = 0; i <= n - 2*mid; i++){ 
                if(ninc[i] >= mid && ninc[i+mid] >= mid) {
                    possible = true;
                    break;
                }
            }

            if(possible){  
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
