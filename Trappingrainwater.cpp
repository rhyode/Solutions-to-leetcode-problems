// 42. Trapping Rain Water Leetcode
//very simple approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //if(n<=2) then there is no two bars to store water in between so zero
        if(n<=2) return 0;
        int totwater = 0;
        //we pre calculate two info about the bars, 1) what is the max bar in the left side and 2)what is the max bar in right side
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
        //how this helps is at a particular i, water can be stored only if both the sides have a greater bar at some x distant
        //and how much water can be stored is the minimum of whatever the max heights on each side minus the height of bar at the i index.
        for(int i=0;i<n;i++){
            if(maxtnowr[i]>height[i] && maxtnowl[i]>height[i]){
                totwater+=min(maxtnowr[i],maxtnowl[i])-height[i];
            }
        }

        return totwater;
    }
};
