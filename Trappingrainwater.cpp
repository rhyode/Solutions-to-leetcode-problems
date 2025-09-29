// 42. Trapping Rain Water Leetcode
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        int totwater = 0;
        vector<int> maxtnowr(n);
        vector<int> maxtnowl(n);
        maxtnowr[n-1] = height[n-1];
        maxtnowl[0] = height[0];
        for(int i =1;i<n;i++){
            maxtnowl[i]=max(maxtnowl[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxtnowr[i] = max(maxtnowr[i+1], height[i]);
        }
        for(int i=0;i<n;i++){
            if(maxtnowr[i]>height[i] && maxtnowl[i]>height[i]){
                totwater+=min(maxtnowr[i],maxtnowl[i])-height[i];
            }
        }

        return totwater;
    }
};
