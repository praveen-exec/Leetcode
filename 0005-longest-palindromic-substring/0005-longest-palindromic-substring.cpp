class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int bestStart = 0;
        int bestLen = 1;

        for(int i = 0; i < n; i++) {

            // -------------------------
            // EVEN length palindrome
            // center = i and i+1
            // -------------------------
            int start = i;
            int end = i + 1;

            while(start >= 0 && end < n && s[start] == s[end]) {

                if(end - start + 1 > bestLen) {
                    bestStart = start;
                    bestLen = end - start + 1;
                }

                start--;
                end++;
            }


            // -------------------------
            // ODD length palindrome
            // center = i
            // -------------------------
            start = i;
            end = i;

            while(start >= 0 && end < n && s[start] == s[end]) {

                if(end - start + 1 > bestLen) {
                    bestStart = start;
                    bestLen = end - start + 1;
                }

                start--;
                end++;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};