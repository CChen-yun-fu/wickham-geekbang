class Solution {
public:
    // ��Ϊk ��������ĸ���
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1;
        int pre = 0, ncount = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end()) {
                ncount += mp[pre - k]; 
            }
            mp[pre]++; // ��Ϊpre �ĸ���
        }
        return ncount;

    }
};