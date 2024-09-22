class Solution {
public:
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};
    bool isValid(vector<vector<char>>& board, int x, int y) {
        int n = board.size();
        int m = board[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;

        return true;
    }
    int minesNearBy(vector<vector<char>>& board, int x, int y) {
        int mines = 0;
        // check in all 4 directions
        for (int dir = 0; dir < 8; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (isValid(board, newX, newY) && board[newX][newY] == 'M')
                mines++;
        }

        return mines;
    }
    void revealBoard(vector<vector<char>>& board, int x, int y) {
        
        if(board[x][y]!='E') return;

        //check for nearby mines
        int mines=minesNearBy(board, x, y);
        if (mines == 0){
            //mark as Blank
            board[x][y] = 'B';

            //reveal adjacent
            for (int dir = 0; dir < 8; dir++) {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];

                if(isValid(board, newX, newY)){
                    revealBoard(board,newX,newY);
                }
            }
        }
        else{
            //we get number of mines
            board[x][y]='0'+mines;
            return;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        // Case 1. it's a mine
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        revealBoard(board,x,y);

        return board;
    }
};