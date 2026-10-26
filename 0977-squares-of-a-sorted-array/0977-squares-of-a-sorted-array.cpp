class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);
        int k = n - 1; 

        while (left <= right) {
            int i = abs(nums[left]);
            int j = abs(nums[right]);
            
            if (i < j) {
                ans[k--] = j * j;
                right--;
            } else { 
                ans[k--] = i * i;
                left++;
            }
        }
        return ans;
    }
};
