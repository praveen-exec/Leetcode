class Solution {
public:
    vector<int> dp;

    int house_rob(vector<int>& nums, int i, int end) {

        // No house left
        if(i > end)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // Rob current house
        int take = nums[i] + house_rob(nums, i + 2, end);

        // Skip current house
        int skip = house_rob(nums, i + 1, end);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Only one house
        if(n == 1)
            return nums[0];

        // Case 1: 0 to n-2
        dp.assign(n, -1);
        int case1 = house_rob(nums, 0, n - 2);

        // Case 2: 1 to n-1
        dp.assign(n, -1);
        int case2 = house_rob(nums, 1, n - 1);

        return max(case1, case2);
    }
};