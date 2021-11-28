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
                    count++; // ͳ�� 1 �ĸ���
                    fa[num(i, j)] = num(i, j); //��ʼ����
                }
                else {
                    fa[num(i, j)] = -1;
                }
            }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;

                for (int k = 0; k < 2; k++) { //  ������������ĵ�
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && nj >= 0 && ni <= m && nj <= n) {
                        if (grid[ni][nj] == '1') { // ��� ���ϵ��ַ�ҲΪ 1 ���򲢼���ǰ���ַ�
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
            count--;   // ÿ����һ�� �ַ���1��������Ҫ��1
        }
    }
    int num(int i, int j) {
        return i * n + j;
    }
};