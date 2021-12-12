class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        for (int i = 0; i < k; i++) { // 将前 k 个数入大根堆
            q.push({ nums[i],i });
        }
        ans.push_back(q.top().first);

        for (int i = k; i < nums.size(); i++) {
            q.push({ nums[i],i });

            while (q.top().second <= i - k) { // 判断 顶部最大的树的位置是否在窗口内，不是在窗口就弹出
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
private:
    priority_queue<pair<int, int>> q;
};