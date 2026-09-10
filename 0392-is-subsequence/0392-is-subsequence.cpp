class Solution {
public:
    bool isSub(string s, string t, int m, int n) {

        // s completely matched
        if (m == 0)
            return true;

        // t finished but s is still remaining
        if (n == 0)
            return false;

        if (s[m-1] == t[n-1]) {
            // characters match -> take both
            return isSub(s, t, m-1, n-1);
        }
        else {
            // characters don't match -> skip t's character
            return isSub(s, t, m, n-1);
        }
    }

    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        return isSub(s, t, m, n);
    }
};