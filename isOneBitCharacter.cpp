// 717. 1-bit and 2-bit Characters
// just find out if the last element in the array which 'has to be 0', has to be paired with the n-2th value, (in case n-2th is 1)

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        vector<bool> paired(n,false);
        for(int i=0;i<n-1;i++){
            if(bits[i]==0) paired[i]=true;
            else if(bits[i]==1){
                paired[i]=true;
                paired[i+1]=true;
                i++;
            }
        }
        if(paired[n-1]==false) return true;
        else return false;
    }
};
