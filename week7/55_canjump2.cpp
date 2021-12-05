class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxStep = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxStep)
                maxStep = max(maxStep, nums[i] + i);
            if (maxStep >= nums.size() - 1) return true;
        }
        return false;

    }
    /*
    *        i:  0  1  2  3  4
    *   nums[i]: 2  3  1  1  4
    *   maxStep: 2  4
    *    result: f  t
    */
};