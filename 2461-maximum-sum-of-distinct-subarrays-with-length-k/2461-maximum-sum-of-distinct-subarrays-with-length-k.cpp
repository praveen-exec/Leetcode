class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long max_sum = 0, sum = 0;
        int n = nums.size(), i = 0;

        unordered_set<int> st;

        for(int j = 0; j < n; j++) {

            // Remove duplicates from the current window
            while(st.contains(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            // Add current element
            st.insert(nums[j]);
            sum += nums[j];

            // Window size becomes k
            if(j - i + 1 == k) {

                max_sum = max(max_sum, sum);

                // Slide window by one position
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }

        return max_sum;
    }
};