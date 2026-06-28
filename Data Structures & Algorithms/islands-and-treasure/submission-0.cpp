class Solution { 
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1 , 1 ,0 , 0};
        int dc[] = {0 , 0 , -1 , 1};
        int target = 2147483647;
        queue<pair<int,int>>q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    q.push({i , j});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == target){
                    grid[nr][nc] = 1 + grid[r][c];
                    q.push({nr , nc});
                }
            }
        }
    }
};
