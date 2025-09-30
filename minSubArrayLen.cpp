///easy binary search approach to the problem
//three steps
// calculate the prefixsumarray of the array nums - since numbers are positive it would be sorted ascending order
// for each index i you need to search for another 'index' which when subtracted from sum till (i-1) gives target
//  you get the index you store it as min inthe minsize variable


class Solution {
public:

    int binsearch(vector<int>& nums, int target, int low){
        int high = nums.size()-1;
        int index=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                index=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return index;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        vector<int> prefixsum(n);
        prefixsum[0] = nums[0];
        int minsize = n+1;
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        for(int i =0;i<n;i++){
            int nt = target +( i==0? 0 : prefixsum[i-1]);
            int index = binsearch(prefixsum, nt, i);
            if(index!=-1){
                minsize = min(minsize,index-i+1);
            }
        }
        return (minsize==n+1)?0:minsize;
    }
};
