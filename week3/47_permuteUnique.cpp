class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;

    void trackBack(vector<int>& nums, vector<bool>& used) {
        if (nums.size() == path.size()) { // 递归终止条件
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue; // 递归时，判断数字是否重复了

           // 递归处理
            if (used[i] == false) {
                path.push_back(nums[i]); // 加入路径
                used[i] = true;
                trackBack(nums, used);
                path.pop_back();  // 状态恢复
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        sort(nums.begin(), nums.end());
        trackBack(nums, used);
        return ans;
    }
};