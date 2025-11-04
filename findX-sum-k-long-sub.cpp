//3318. Find X-Sum of All K-Long Subarrays I
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        for(int i =0;i<n-k+1;i++){
            unordered_map<int,int> freq;
            for(int j=i;j<k+i;j++){
                freq[nums[j]]++;
            }
            if(freq.size()<x){
                int tempsum = 0;
                for(int j=i;j<k+i;j++){
                    tempsum+=nums[j];
                }
                answer.push_back(tempsum);
            }
            else{
                vector<pair<int,int>> valuenum; //pairs with value as key and num as value
                for(const auto& it: freq){
                    valuenum.push_back({it.second,it.first});
                }
                sort(valuenum.begin(),valuenum.end(),greater<pair<int,int>>());
                int tempsum=0;
                for(int i=0;i<x;i++){
                    tempsum+=(valuenum[i].first*valuenum[i].second);
                }
                answer.push_back(tempsum);

            }
        }
        return answer;
    }
};
