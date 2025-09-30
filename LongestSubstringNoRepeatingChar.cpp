//Leetcode 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        int maxlength = 1;
        int left =0 ;
        unordered_map<char,int> indexchar;
        for(int i=0;i<n;i++){
            if(indexchar.count(s[i])!=0){
                left = max(left, indexchar[s[i]] + 1);
            }
            indexchar[s[i]] = i;
            maxlength = max(maxlength,i-left+1);
        }
        return maxlength;
    }
};
