class Solution {
public:
    vector<int> dp;
    int house_rob(vector<int> &nums,int n){
        
      //if no house
      if(n < 0) 
        return 0;

      if(dp[n] != -1) return dp[n];
      
      int take = nums[n] + house_rob(nums,n-2);

      int skip = house_rob(nums,n-1);

      dp[n]=max(take , skip);

      return dp[n];
    }
    int rob(vector<int>& nums) {
     int n=nums.size();

     dp.resize(n+1,-1);
     return house_rob(nums,n-1);

    }
};