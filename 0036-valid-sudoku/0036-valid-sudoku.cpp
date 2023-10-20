class Solution {
public:
    bool validate(vector<vector<char>>& board, int row, int col, int num) {
        board[row][col] = '.';
        // col
        for(int i=0; i<9; i++) {
            if(board[i][col] == (char)(num+'0'))
                return false;
        }
        // row
        for(int j=0; j<9; j++) {
            if(board[row][j] == (char)(num+'0'))
                return false;
        }
        // grid
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i=sr; i<sr+3; i++) {
            for(int j=sc; j<sc+3; j++) {
                if(board[i][j] == (char)(num+'0'))
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    if(validate(board, i, j, board[i][j]-'0')==false)
                        return false;
                }
            }
        }
        return true;
    }
};