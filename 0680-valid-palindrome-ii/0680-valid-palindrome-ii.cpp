class Solution {
   public:
    bool validPalindrome(string s) {
        int n = s.length();
        int start = 0, end = n - 1;

        while (start <= end) {
           if (s[start] != s[end])
                return isPalindrome(s, start + 1, end) ||                                isPalindrome(s, start, end - 1);
            start++;
            end--;
        }
        return true;
    }

   private:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }

        return true;
    }
};