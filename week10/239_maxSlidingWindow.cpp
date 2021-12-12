class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        for (int i = 0; i < k; i++) { // ��ǰ k ����������
            q.push({ nums[i],i });
        }
        ans.push_back(q.top().first);

        for (int i = k; i < nums.size(); i++) {
            q.push({ nums[i],i });

            while (q.top().second <= i - k) { // �ж� ������������λ���Ƿ��ڴ����ڣ������ڴ��ھ͵���
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
private:
    priority_queue<pair<int, int>> q;
};