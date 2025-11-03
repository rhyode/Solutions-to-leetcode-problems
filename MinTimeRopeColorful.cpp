//1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int answer = 0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                int maxtime = neededTime[i-1];
                answer += neededTime[i-1];
                while(i<n && colors[i]==colors[i-1]){
                    maxtime = max(maxtime,neededTime[i]);
                    answer+=neededTime[i];
                    i++;
                }
                answer-=maxtime;
            }
        }
        return answer;
    }
};
