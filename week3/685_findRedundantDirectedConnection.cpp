class Solution {
public:
    vector<int> parents;
    int count;
    int MyFind(int a) {
        while (a != parents[a]) {
            parents[a] = parents[parents[a]];// 稍微压缩一下路径
            a = parents[a];
        }
        return a;
    }
    bool IsConnect(int a, int b) {
        int p1 = MyFind(a);
        int p2 = MyFind(b);
        return p1 == p2;
    }
    void MyUnion(int a, int b) {
        int p1 = MyFind(a);
        int p2 = MyFind(b);
        if (p1 == p2) return;
        parents[p1] = p2;
        count--;
        return;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 统计大家出入度，并找到入度为2的终点（若有的话）
        int n = edges.size(); // n个顶点，注意顶点从1开始
        vector<int> inDegree(n); // 入度
        int end = -1;
        for (auto& e : edges) {
            inDegree[e[1] - 1]++; // 入度+1
            if (inDegree[e[1] - 1] > 1) end = e[1];
        }

        // 并查集初始化
        count = edges.size();
        parents.resize(count);
        for (int i = 0; i < count; ++i) {
            parents[i] = i;
        }
        // 若有end，则为情况1、2，答案为指向end的两条边之一
        if (-1 != end) {
            bool is_first = true;
            vector<int> edge_first;
            vector<int> edge_second;
            for (auto& e : edges) {
                // 对于指向end的两条边，只合并第一条，看最后是否能联通
                if (e[1] == end) {
                    if (is_first) {
                        is_first = false;
                        MyUnion(e[0] - 1, e[1] - 1);
                        edge_first = e;
                    }
                    else {
                        edge_second = e;
                    }
                }
                else {
                    MyUnion(e[0] - 1, e[1] - 1);
                }
            }

            // 有可能删掉任意边都行，这时优先返回靠后的边，即second
            if (1 == count) return edge_second;
            else return edge_first;
        }
        // 若无end，则删除环路中任意一条边都行，按照题意，删除环路中最后出现的那条边
        else {
            for (auto& e : edges) {
                // 若将添加的边已经有连接了，则该边可删除
                if (IsConnect(e[0] - 1, e[1] - 1)) {
                    return e;
                }
                MyUnion(e[0] - 1, e[1] - 1);
            }
        }
        return vector<int>();
    }
};