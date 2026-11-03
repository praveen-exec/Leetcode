class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        
        //step1 : cycle detection algorithm
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow != fast);
        
        //step 2 : finding the meet point 

        int n1=slow; // or fast
        int n2=0; //start new pointer from head

        while(n1 != n2){
            n1=nums[n1];
            n2=nums[n2];
        }
        return n1; //or n2
    }
};