class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fa = vector<int>(1001, 0); // 最长的长度为1000，所以开辟1001的空间
        for (int i = 0; i < n; i++) fa[i] = i;  // 对每个分支初始化

        for (auto edge : edges) { 
            int x = find(edge[0]);
            int y = find(edge[1]);
            if (x == y) { // 如果 有公共的祖先，则说明这两点是连通的
                return edge;
            }
            else {
                fa[x] = y; // 并集子集
            }
        }
        return { };
    }
private:
    vector<int>fa;

    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void unioset(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }
    /*
          1
        /  \    
       2  -  3 
       init: fa[1] = 1,fa[2] = 2.fa[3]=3;
       first  [1,2]: fa[2] = 1
       secend [1,3]: fa[3] = 1
       third  [2,3]: fa[2] = fa[3] 
    */
};