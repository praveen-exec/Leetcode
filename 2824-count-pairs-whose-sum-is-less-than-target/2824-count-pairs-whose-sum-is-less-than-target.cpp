class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//sort
        int n=nums.size();
        int i=0,j=n-1,count=0;
        while(i < j){
          if( nums[i] + nums[j] < target)
           {
            count += j-i;
            i++;
           }
           else j--;
        }
        return count;
    }
};