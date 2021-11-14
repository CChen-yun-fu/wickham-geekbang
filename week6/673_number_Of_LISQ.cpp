class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int dp[nums.size()];   // dp[i] Record the number of current subsequences 
        int count[nums.size()]; // count[i] record the number of the dp[i]
        int maxValue = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = count[i] = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
                if (dp[i] > maxValue) maxValue = dp[i];// update the value of the largest sub queue
            }
        }
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (maxValue == dp[i])
                ans += count[i];
        }
        return ans;
    }
    //eg:
    //   nums[] : 1  3  5  4  7
    //     dp[] : 1  2  3  3  4
    //  count[] : 1  1  1  1  2
};