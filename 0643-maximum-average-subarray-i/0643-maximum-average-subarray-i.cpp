class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        double max_sum=INT_MIN,sum=0;
        
        for(j=0; j < k; j++)
          sum += nums[j];

        max_sum = sum;

        while(j < n){
          sum += nums[j];
          sum -= nums[i];

          max_sum = max(max_sum,sum);

          i++;
          j++;
        }

        return max_sum/k;
    }
};