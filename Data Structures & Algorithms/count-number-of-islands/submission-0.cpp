class Solution {
private:
    void dfs(int row , int col , vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int dr[] = {-1 , 1 ,0 , 0};
        int dc[] = {0 , 0 , -1 , 1};
        q.push({row , col});
        grid[row][col] = '0';
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1'){
                    q.push({nr , nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    dfs(i , j , grid);
                    count ++;
                }
            }
        }
        return count;
    }
};