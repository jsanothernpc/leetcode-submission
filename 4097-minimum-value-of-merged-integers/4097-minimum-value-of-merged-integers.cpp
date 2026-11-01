class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i += 2) {
            int a = nums[i];
            int b = nums[i + 1];
            int temp = b;
            int multiplier = 1;
            while (temp > 0) {
                multiplier *= 10;
                temp /= 10;
            }
            int merged = a * multiplier + b;
            mini = min(mini, merged);
        }
        return mini;
    }
};