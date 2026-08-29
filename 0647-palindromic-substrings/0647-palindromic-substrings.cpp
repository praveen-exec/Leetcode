class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        // Check for all centers
        for(int center = 0; center < n; center++) {
            
            // Odd length palindrome
            int left = center, right = center;
            while(left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            // Even length palindrome
            left = center;
            right = center + 1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;  
    }
};
