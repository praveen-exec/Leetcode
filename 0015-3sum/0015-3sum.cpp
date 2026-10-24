class Solution {
public:
    vector<vector<int>> ans;
    void two_sum(vector<int> &nums,int start,int end,int target){
        while(start<end){

            int sum = nums[start] + nums[end];
            if(sum < target)
              start++;
            else if(sum > target)
              end--;
            else
            { 
            //first remove the duplicates from either end
            while(start < end && nums[start]==nums[start+1]) 
              start++;
            while(start < end && nums[end-1]==nums[end]) 
              end--;

            ans.push_back({-target,nums[start],nums[end]});
            start++;
            end--;
            }
        }

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n=nums.size();
      
      if(n < 3) return {};

      sort(nums.begin(),nums.end()); //sort in ascending ord

      for(int i=0; i<=n-3 ;i++){

        //skip if n1 is chosen earlier
        if(i>0 && nums[i]==nums[i-1])
          continue;

        int n1 = nums[i];
        int target = -n1;
        
        two_sum(nums,i+1,n-1,target);
      }
      return ans;
    }
};