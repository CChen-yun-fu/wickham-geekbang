class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int colunm = triangle[row - 1].size();
        int dp[row][colunm];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];  //每一行的首个dp

            for (int j = 1; j < i; j++) {
                dp[i][j] = min(triangle[i][j] + dp[i - 1][j], triangle[i][j] + dp[i - 1][j - 1]); // 每一行的状态值
            }

            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];  // 每一行最后一个dp ,等于上一行dp最后的一个加上现在值。
        }

        // 遍历 dp 最后一行 的最小值
        int ans = dp[row - 1][0];
        for (int i = 0; i < colunm; i++) {
            ans = min(ans, dp[row - 1][i]);
        }
        return ans;
    }
    // -1                  -1
    //  2  3      =====>   -1  2
    //  1 -1  -3            0  1  -1
    /*
     *状态方程 dp[i][j] = min(triangle[i][j] + dp[i][j-1],triangle[i][j] + dp[i][j])
     * 但每一行的开头与吗，末尾要特别处理，防止越界
     *
     */
};