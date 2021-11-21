class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int tempMin = 1e9;
            for (int j = 1; j * j <= i; j++) {
                tempMin = min(tempMin, dp[i - j * j]);
            }
            dp[i] = tempMin + 1;
        }
        return dp[n];
    }
};