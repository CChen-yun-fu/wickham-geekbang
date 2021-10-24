class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;

    void trackBack(vector<int>& nums, vector<bool>& used) {
        if (nums.size() == path.size()) { // �ݹ���ֹ����
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue; // �ݹ�ʱ���ж������Ƿ��ظ���

           // �ݹ鴦��
            if (used[i] == false) {
                path.push_back(nums[i]); // ����·��
                used[i] = true;
                trackBack(nums, used);
                path.pop_back();  // ״̬�ָ�
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