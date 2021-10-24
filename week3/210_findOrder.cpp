class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        canFinish(numCourses, prerequisites);
        if (ans.size() == numCourses) return ans;
        else return {};
    }
    void canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        to = vector<vector<int>>(numCourses, vector<int>());
        indeg = vector<int>(numCourses, 0);
        for (vector<int>& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            to[bi].push_back(ai);
            indeg[ai]++;
        }
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i); // 找到度为零的边
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int y : to[x]) { // 从x 出发 深度遍历与它有关的点
                indeg[y]--;
                if (indeg[y] == 0) { // 如果找到一个度为0.即不是环的点就加入
                    q.push(y);
                }
            }
        }
    }

private:
    vector<vector<int>> to;
    vector<int>indeg;
    vector<int> ans;
};