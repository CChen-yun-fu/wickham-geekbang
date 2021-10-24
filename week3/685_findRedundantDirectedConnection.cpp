class Solution {
public:
    vector<int> parents;
    int count;
    int MyFind(int a) {
        while (a != parents[a]) {
            parents[a] = parents[parents[a]];// ��΢ѹ��һ��·��
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
        // ͳ�ƴ�ҳ���ȣ����ҵ����Ϊ2���յ㣨���еĻ���
        int n = edges.size(); // n�����㣬ע�ⶥ���1��ʼ
        vector<int> inDegree(n); // ���
        int end = -1;
        for (auto& e : edges) {
            inDegree[e[1] - 1]++; // ���+1
            if (inDegree[e[1] - 1] > 1) end = e[1];
        }

        // ���鼯��ʼ��
        count = edges.size();
        parents.resize(count);
        for (int i = 0; i < count; ++i) {
            parents[i] = i;
        }
        // ����end����Ϊ���1��2����Ϊָ��end��������֮һ
        if (-1 != end) {
            bool is_first = true;
            vector<int> edge_first;
            vector<int> edge_second;
            for (auto& e : edges) {
                // ����ָ��end�������ߣ�ֻ�ϲ���һ����������Ƿ�����ͨ
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

            // �п���ɾ������߶��У���ʱ���ȷ��ؿ���ıߣ���second
            if (1 == count) return edge_second;
            else return edge_first;
        }
        // ����end����ɾ����·������һ���߶��У��������⣬ɾ����·�������ֵ�������
        else {
            for (auto& e : edges) {
                // ������ӵı��Ѿ��������ˣ���ñ߿�ɾ��
                if (IsConnect(e[0] - 1, e[1] - 1)) {
                    return e;
                }
                MyUnion(e[0] - 1, e[1] - 1);
            }
        }
        return vector<int>();
    }
};