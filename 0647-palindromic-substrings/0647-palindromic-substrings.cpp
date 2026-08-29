//Brute force ==> O(n^3)
class Solution {
public:

    bool ispalindrome(string &s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }

        return true;
    }

    int countSubstrings(string s) {

        int count = 0;

        for (int i = 0; i < s.length(); i++) {

            for (int j = i; j < s.length(); j++) {

                // substring(start, length)
                string temp = s.substr(i, j - i + 1);

                if (ispalindrome(temp)) {
                    count++;
                }
            }
        }

        return count;
    }
};

<br>

//Optimized ==> O(n^2)
class Solution {
public:

    bool ispalindrome(string &s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }

        return true;
    }

    int countSubstrings(string s) {

        int count = 0;

        for (int i = 0; i < s.length(); i++) {

            for (int j = i; j < s.length(); j++) {

                // substring(start, length)
                string temp = s.substr(i, j - i + 1);

                if (ispalindrome(temp)) {
                    count++;
                }
            }
        }

        return count;
    }
};
