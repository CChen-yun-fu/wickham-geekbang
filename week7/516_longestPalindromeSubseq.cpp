class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;  //��ʼ���Խ���

        for (int i = n - 1; i >= 0; i--) { // �ӵײ���ʼ����ת�Ʒ���
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2; // �������s[i] == s[j],�򳤶�Ϊs �� i+1 �� j-1�����ַ����ĳ��ȼ� 2
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // �������ȣ����ж�ȡ���ַ��� subStr(i+1,j) ��subStr(i,j-1)�����ֵ
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
    *  i = n-1 ʱ�����ַ���b�ĳ��� Ϊ 1
       i = n-2 ʱ��j = n-1; ���ַ���ab���ӳ��ȣ�dp[n-2][n-1] = max(dp[n-1][n-1],dp[n-2][n-2]) = 1;
       i = n-3 ʱ��j = n-2; ���ַ���ba���ӳ���,dp[n-3][n-2] = max(dp[n-2][n-2],dp[n-3][n-3]) = 1;
                   j = n-1; ���ַ���bab���ӳ���,dp[n-3][n-1] = max(dp[n-2][n-1],dp[n-3][n-2]) = 1;
       i = n-4 ʱ��j = n -3

    */
};