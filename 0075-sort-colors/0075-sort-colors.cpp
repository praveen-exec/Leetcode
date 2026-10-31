//Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,k=0,j=nums.size()-1;
        
        //stop when k cross j
        while(k <= j){

          if(nums[k] == 1){
           k++;
          }
          // k ke paas 2 ho toh swap with j
          else if(nums[k] == 2){
           int temp = nums[k];
            nums[k] = nums[j];
            nums[j] = temp;
            
            j--;
          }

          else{
            int temp = nums[k];
             nums[k] = nums[i];
             nums[i] = temp;

            i++;
            k++;
          }
        }
    }
};