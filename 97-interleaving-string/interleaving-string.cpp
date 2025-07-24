class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

        // If lengths don't match, it's impossible to interleave
        if (n1 + n2 != n3) return false;

        // dp[j] indicates whether s3[0..i+j-1] can be formed
        vector<bool> dp(n2 + 1, false);
        dp[0] = true; // Empty strings can interleave to form an empty string

        // Initialize for the case where s1 is empty
        for (int j = 1; j <= n2; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= n1; i++) {
            // Update for the first column where s2 is empty
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];

            for (int j = 1; j <= n2; j++) {
                // The character in s3 must match either s1 or s2
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n2];
    }
};