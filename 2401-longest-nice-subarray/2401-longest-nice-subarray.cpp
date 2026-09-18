class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int usedBit = 0;
        int res = 0;
        for(int j=0;j<nums.size();j++){
            while((usedBit & nums[j])!=0){
                usedBit ^= nums[i];
                i++;
            }
            usedBit |= nums[j];
            res = max(res,j-i+1);
        }
        return res;
    }
};