class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)  return;
        int numland = 0;
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {// ��һ�� �Ƚ� �߽���ϵ� ��O��,����dfs ����ǰ��������"O"��Ϊ "O"
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && (i == row - 1 || col - 1 == j || i == 0 || j == 0)) { //�߽�����
                    numland++;
                    dnf(board, i, j);
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') { // �����Ǳ߽��"O",��ΪX
                    board[i][j] = 'X';
                }
                if (board[i][j] == '*') {// �ָ���߽�������"O";
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

        // ��ȱ�������ǰ����������Ϊ1 �Ľڵ�Ϊ�����㣬��������Ϊ0��
        if (row - 1 >= 0 && grid[row - 1][col] == 'O') dnf(grid, row - 1, col);//��
        if (row + 1 <= nrow - 1 && grid[row + 1][col] == 'O') dnf(grid, row + 1, col);//��
        if (col - 1 >= 0 && grid[row][col - 1] == 'O') dnf(grid, row, col - 1);// ��
        if (col + 1 <= ncol - 1 && grid[row][col + 1] == 'O') dnf(grid, row, col + 1);// ��
    }
};