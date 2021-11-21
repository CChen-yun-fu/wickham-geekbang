class Solution {
public:
    int jump(vector<int>& nums) {
        //     int now = 0;
        //     int ans = 0;
        //     while(now < nums .size() -1){
        //         int right = now +nums[now];
        //         if(right >= nums .size()-1) {
        //             return ans+1;
        //         }

        //         int nextRight = right;
        //         int next = now;
        //         for(int i = now+1;i<= right;i++){
        //             if(nums[i] + i > nextRight){
        //                 nextRight = nums[i] + i;
        //                 next = i;
        //             }
        //         }
        //         now = next;
        //         ans++;
        //     }
        //     return ans;
        // }

        int leght = nums.size();
        int dp[leght];
        dp[0] = 0;

        for (int i = 1; i < leght; i++) {
            dp[i] = 1e9;
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[leght - 1];
    }
};