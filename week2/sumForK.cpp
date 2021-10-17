class Solution {
public:
    // 和为k 的子数组的个数
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1;
        int pre = 0, ncount = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end()) {
                ncount += mp[pre - k]; 
            }
            mp[pre]++; // 和为pre 的个数
        }
        return ncount;

    }
};