class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)  return;
        int numland = 0;
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {// 第一步 先将 边界的上的 “O”,进行dfs 将与前其相连的"O"置为 "O"
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && (i == row - 1 || col - 1 == j || i == 0 || j == 0)) { //边界条件
                    numland++;
                    dnf(board, i, j);
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') { // 将不是边界的"O",置为X
                    board[i][j] = 'X';
                }
                if (board[i][j] == '*') {// 恢复与边界相连的"O";
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dnf(vector<vector<char>>& grid, int row, int col)
    {
        int nrow = grid.size();
        int ncol = grid[0].size();

        grid[row][col] = '*';

        // 深度遍历将当前的上下左右为1 的节点为出发点，并将其置为0；
        if (row - 1 >= 0 && grid[row - 1][col] == 'O') dnf(grid, row - 1, col);//上
        if (row + 1 <= nrow - 1 && grid[row + 1][col] == 'O') dnf(grid, row + 1, col);//下
        if (col - 1 >= 0 && grid[row][col - 1] == 'O') dnf(grid, row, col - 1);// 左
        if (col + 1 <= ncol - 1 && grid[row][col + 1] == 'O') dnf(grid, row, col + 1);// 右
    }
};