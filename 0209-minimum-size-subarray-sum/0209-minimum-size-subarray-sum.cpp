class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,sum=0,min_len=INT_MAX;

        for (int j=0; j<nums.size(); j++) {

            sum += nums[j];  // Expand window

            while (sum >= target) {
                min_len = min(min_len, j - i + 1);

                // Shrink window
                sum -= nums[i];
                i++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};