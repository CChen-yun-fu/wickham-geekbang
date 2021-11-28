class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        const int dx[4] = { -1,0,0,1 };
        const int dy[4] = { 0,-1,1,0 };
        fa = vector<int>(m * n + 1, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++; // 统计 1 的个数
                    fa[num(i, j)] = num(i, j); //初始化表集
                }
                else {
                    fa[num(i, j)] = -1;
                }
            }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;

                for (int k = 0; k < 2; k++) { //  左、上两个方向的点
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && nj >= 0 && ni <= m && nj <= n) {
                        if (grid[ni][nj] == '1') { // 如果 左、上的字符也为 1 ，则并集当前的字符
                            unioset(num(i, j), num(ni, nj));
                        }
                    }
                }
            }
        }
        return count;
    }
private:
    vector<int>fa;
    int m, n;
    int count = 0;

    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void unioset(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            fa[x] = y;
            count--;   // 每并集一个 字符‘1’，个数要减1
        }
    }
    int num(int i, int j) {
        return i * n + j;
    }
};