class Solution {
public:
   // TC : O(logn)
   // SC : O(1)
    int sum_of_digits(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit*digit;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        while(fast != 1){
           slow = sum_of_digits(slow);
           fast = sum_of_digits(sum_of_digits(fast));

           if(slow == fast && fast!=1)
             return false;

        }
        return true;
    }
};
