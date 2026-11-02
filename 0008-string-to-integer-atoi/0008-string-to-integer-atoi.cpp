class Solution {
public:
    int myAtoi(string s) {

        int i = 0, n = s.length();
        int ans = 0, sign = 1;

        // Step 1: Skip leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        }

        // Step 3: Convert digits
        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Handle overflow. --> INT_MAX % 10 =7
            if(ans > INT_MAX / 10 ||
              (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {

                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};