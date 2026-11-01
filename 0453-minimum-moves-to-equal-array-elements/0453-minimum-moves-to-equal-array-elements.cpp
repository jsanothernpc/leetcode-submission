class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = ranges::min(nums);
        int count = 0;
        for(int n : nums) count += n - mini;
        return count;
        
    }
};