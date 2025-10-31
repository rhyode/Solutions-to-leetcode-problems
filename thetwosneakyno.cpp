// Leetcode 3289. The Two Sneaky Numbers of Digitville
// hashmap/vector way to do - mapping
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> answer;
        unordered_map<int,int> frequency;
        for(int num:nums){
            frequency[num]++;
            if(frequency[num]==2) answer.push_back(num);
        }
        return answer;
    }
};




//sorting easy method
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> answer;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) answer.push_back(nums[i]);
        }
        return answer;
    }
};
