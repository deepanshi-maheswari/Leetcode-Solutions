class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};
    
    bool solve(vector<vector<char>>& board, string word, int i, int j, int w){
        if(w == word.size()){
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[w]){
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';

        for(int k = 0; k < 4; k++){
            int nrow = i + rows[k];
            int ncol = j + cols[k];

            if(solve(board, word, nrow, ncol, w + 1)){
                return true;
            }
        }

        board[i][j] = ch;

        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int r = 0;
        int c = 0;

        int w = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[w]){
                    if(solve(board, word, i, j, w)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};