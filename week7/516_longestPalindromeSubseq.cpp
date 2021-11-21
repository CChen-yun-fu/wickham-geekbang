class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;  //初始化对角线

        for (int i = n - 1; i >= 0; i--) { // 从底部开始向上转移方程
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2; // 如果是是s[i] == s[j],则长度为s 的 i+1 到 j-1的子字符串的长度加 2
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 如果不相等，则判断取子字符串 subStr(i+1,j) 或subStr(i,j-1)的最大值
            }
        }
        return dp[0][n - 1];
    }
    /*
    *     b  b  b  a  b
    *  b  1
    *  b  0  1
    *  b     0  1
    *  a        0   1
    *  b            0  1
    *
    *  i = n-1 时，求字符串b的长度 为 1
       i = n-2 时，j = n-1; 求字符串ab的子长度，dp[n-2][n-1] = max(dp[n-1][n-1],dp[n-2][n-2]) = 1;
       i = n-3 时，j = n-2; 求字符串ba的子长度,dp[n-3][n-2] = max(dp[n-2][n-2],dp[n-3][n-3]) = 1;
                   j = n-1; 求字符串bab的子长度,dp[n-3][n-1] = max(dp[n-2][n-1],dp[n-3][n-2]) = 1;
       i = n-4 时，j = n -3

    */
};