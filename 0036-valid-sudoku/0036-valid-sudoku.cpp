class Solution {
public:
    bool valid(vector<vector<char>>& board, int i, int j) {
        char c = board[i][j];
        board[i][j] = '.';
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) return false;
            if (board[k][j] == c) return false;
            if (board[3*(i/3) + (k/3)][3*(j/3) + (k%3)] == c) return false;
        }    
        board[i][j] = c;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    bool ok = valid(board, i, j);
                    if (!ok) return false;
                }
            }
        }
        
        return true;
    }
};