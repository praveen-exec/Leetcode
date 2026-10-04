class Solution {
public:
    //Time : O(logn)  Space: O(1)
    int nextSum(int n){
        int sum=0;
        
        while(n > 0){

         int digit = n % 10;
         sum += digit * digit;
         n /=10;

        }
        return sum;
    }

    //Floyd's Cycle Detection Algorithm
    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        while(true){
            slow=nextSum(slow);
            fast=nextSum(nextSum(fast));

            if(fast == 1) 
              return true;
            
            if(slow == fast)
              return false;
        }
    }
};