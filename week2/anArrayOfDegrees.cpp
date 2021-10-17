class Solution {
public:
    //数组的度
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++; //元素的次数
                mp[nums[i]][2] = i; //元素在数组的最远位置
            }
            else {
                mp[nums[i]] = { 1,i,i };//如果不在map 中，则插入，（1，i，i）代表 出现一次，初次与最后出现的位置都是i
            }
        }
        int maxnums = 0; //元素出现最多的次数
        int minlen = 0;
        for (auto& [_, vec] : mp) {
            if (maxnums < vec[0]) {
                maxnums = vec[0];
                minlen = vec[2] - vec[1] + 1;// 更新出现次数最多的元素的跨度（最后出现的位置-初次出现的位置）
            }
            else  if (maxnums == vec[0]) {
                if (minlen > vec[2] - vec[1] + 1)
                    minlen = vec[2] - vec[1] + 1;//更新度
            }
        }
        return minlen;
    }
};