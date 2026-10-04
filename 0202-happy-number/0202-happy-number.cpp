class Solution {
public:
    // Time: O(log n)  // Space: O(log n)
    int nextSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        set<int> seen;

        while (n != 1) {
            // Cycle detected
            if (seen.count(n))
                return false;

            seen.insert(n);

            // Generate next number
            n = nextSum(n);
        }
        return true;
    }
};

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
