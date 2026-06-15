class Solution {
public:

    bool solve(vector<vector<char>>& board ,string word , int rows , int columns , int index){
        if(index == word.size()){
            return true;
        }
        if(rows < 0 || rows >= board.size() || columns < 0 || columns >= board[0].size() || board[rows][columns] != word[index]){
            return false;
        }
        char temp = board[rows][columns];
        board[rows][columns] = '#';

        if(
            solve(board , word , rows + 1 , columns , index + 1) ||
            solve(board , word , rows - 1 , columns , index + 1) ||
            solve(board , word , rows , columns + 1 , index + 1) ||
            solve(board , word , rows , columns - 1 , index + 1)
        ){
            return true;
    
        }
        board[rows][columns] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();
        int index = 0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < columns ; j++){
                if(solve(board , word , i , j , index)){
                    return true;
                }
            }
        }
        return false;
    }
};