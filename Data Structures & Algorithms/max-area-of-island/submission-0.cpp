class Solution {
private:
    int bfs(int row , int col , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int dr[] = {-1 , 1 ,0 , 0};
        int dc[] = {0 , 0 , -1 , 1};
        q.push({row , col});
        int area = 1;
        grid[row][col] = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    q.push({nr , nc});
                    area ++;
                    grid[nr][nc] = 0;
                }
            }
        }
        return area;
    }      
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int area = bfs(i , j , grid);
                    maxArea = max(area , maxArea);
                }
            }
        }
        return maxArea;
    }
};