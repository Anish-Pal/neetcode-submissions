class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dr[] = {-1 , 1 , 0 , 0};
        int dc[] = {0 , 0 , -1 , 1};
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                q.push({0 , i});
                board[0][i] = '#';
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O'){
                q.push({i , 0});
                board[i][0] = '#';
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[m-1][i] == 'O'){
                q.push({m - 1 , i});
                board[m-1][i] = '#';
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(board[i][n-1] == 'O'){
                q.push({i , n - 1});
                board[i][n-1] = '#';
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O'){
                    q.push({nr , nc});
                    board[nr][nc] = '#';
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] != '#'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};