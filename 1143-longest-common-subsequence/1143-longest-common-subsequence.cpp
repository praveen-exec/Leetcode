class Solution {
public:
    //Top Down Approach
    vector<vector<int>> dp;

    int LCS(string text1, string text2, int m, int n) {

        // Base Case
        if (m == 0 || n == 0)
            return 0;

        // Already calculated
        if (dp[m][n] != -1)
            return dp[m][n];

        // Last characters match
        if (text1[m - 1] == text2[n - 1]) {
            dp[m][n] = 1 + LCS(text1, text2, m - 1, n - 1);
        }
        //Last Character not match
        else {
            dp[m][n] = max(
                LCS(text1, text2, m - 1, n),
                LCS(text1, text2, m, n - 1)
            );
        }

        return dp[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        // Create DP table
        dp.resize(m + 1, vector<int>(n + 1, -1));

        return LCS(text1, text2, m, n);
    }
};


class Solution {
public:
    //Bottom UP -->Approach
    int LCS(string text1, string text2, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m,n;
        m = text1.length();
        n = text2.length();

        return LCS(text1, text2, m, n);
    }
};
