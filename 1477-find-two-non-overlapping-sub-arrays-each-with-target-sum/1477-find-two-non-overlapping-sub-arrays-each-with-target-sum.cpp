class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> bestlen(n, INT_MAX);

        int i = 0, currSum = 0;
        int res = INT_MAX;
        int best = INT_MAX;

        for (int j = 0; j < n; j++) {
            currSum += nums[j];

            while (i <= j && currSum > target) {
                currSum -= nums[i++];
            }

            if (currSum == target) {
                int len = j - i + 1;

                if (i > 0 && bestlen[i - 1] != INT_MAX)
                    res = min(res, len + bestlen[i - 1]);

                best = min(best, len);
            }

            bestlen[j] = best;
        }

        return res == INT_MAX ? -1 : res;
    }
};
