class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeSolution(vector<vector<char>>& board, int n, vector<vector<string>>& ans){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string output = "";
            for(int j = 0; j < n; j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, int n){
        if(rowCheck[row] == true)
            return false;

        if(upperLeftDiagonalCheck[n-1+col-row] == true)
            return false;

        if(bottomLeftDiagonalCheck[col+row] == true)
            return false;

        return true;
        
        //check krana chahate h, kya mai current cell [row, col] pr Queen rakh 
        //sakata hu ya nhi
        //check upper left diagonal, left row, bottom left diagonal
        // int i = row;
        // int j = col;
    
        // //check row
        // while(j >= 0){
        //     if(board[i][j] == 'Q'){
        //         return false;
        //     }
        //     j--;
        // }

        // //check upper left diagonal
        // i = row;
        // j = col;
        // while(i >= 0 && j >= 0){
        //     if(board[i][j] == 'Q'){
        //         return false;
        //     }
        //     i--;
        //     j--;
        // }

        // //check bottom left diagonal
        // i = row;
        // j = col;
        // while(i < n && j >= 0){
        //     if(board[i][j] == 'Q'){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }

        // //kahi pr bhi queen nhi mili
        // //iska matlab position safe hai
        // //iska mt return kr do true
        // return true;

    }

    void solve(vector<vector<char>>& board, int col, int n, vector<vector<string>>& ans){
        //base case
        if(col >= n){
            storeSolution(board, n, ans);
            return;
        }

        //1 case solve karna h , baki recursion sambhal lega
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                //rakh do
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n-1+col-row] = true;
                bottomLeftDiagonalCheck[row+col] = true;

                //recursive solution laega
                solve(board, col+1, n, ans);
                //backtracking
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n-1+col-row] = false;
                bottomLeftDiagonalCheck[row+col] = false;

            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string> >ans;

        int col = 0;
        //0 -> empty call
        //1 -> Queen at the cell
        solve(board, col, n, ans);
        return ans;
    }
};