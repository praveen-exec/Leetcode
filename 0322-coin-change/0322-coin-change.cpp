class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //create dp array and initialize with amount + 1  
        vector<int> dp(amount + 1, amount + 1);

        // Base case
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {
                //we are checking if coin is less than  equal to amount i 
                if (coin <= i) {
                    dp[i] = min(dp[i],
                                dp[i - coin] + 1);
                }
            }
        }  
//checking the invalid case --> kyuki humne amount+1 se intialize kara tha
       if (dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};
