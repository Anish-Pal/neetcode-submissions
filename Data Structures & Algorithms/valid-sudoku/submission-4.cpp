class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowset[9];
        unordered_set<char> colset[9];
        unordered_set<char> boxset[9];

        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                char val = board[i][j];

                if(val == '.'){
                    continue;
                }

                if(rowset[i].count(val)){
                    return false;
                }
                rowset[i].insert(val);

                if(colset[j].count(val)){
                    return false;
                }
                colset[j].insert(val);


                int idx = (i / 3) * 3 + (j / 3);
                if(boxset[idx].count(val)){
                    return false;
                }
                boxset[idx].insert(val);
            }
        }
      return true;
    }
};
