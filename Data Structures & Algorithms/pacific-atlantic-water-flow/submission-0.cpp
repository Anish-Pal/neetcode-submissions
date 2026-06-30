class Solution {
private:
    void bfs(queue<pair<int , int>>&q , vector<vector<bool>>&visit , vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        int dr[] = {-1 , 1 ,0 , 0};
        int dc[] = {0 , 0 , -1 , 1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && visit[nr][nc] == false && heights[row][col] <= heights[nr][nc]){
                    q.push({nr , nc});
                    visit[nr][nc] = true;
                }
            }
        }
    }    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>>pacificBool(m , vector<bool>(n , false));
        vector<vector<bool>>atlanticBool(m , vector<bool>(n , false));
        queue<pair<int , int>>qpac;
        queue<pair<int , int>>qata;

        for(int i = 0 ; i < n ; i++){
            qpac.push({0 , i});
            pacificBool[0][i] = true;
        }
        for(int i = 0 ; i < m ; i++){
            qpac.push({i , 0});
            pacificBool[i][0] = true;
        }

        for(int i = 0 ; i < n ; i++){
            qata.push({m - 1 , i});
            atlanticBool[m-1][i] = true;
        }
        for(int i = 0 ; i < m ; i++){
            qata.push({i , n - 1});
            atlanticBool[i][n-1] = true;
        }

        bfs(qpac , pacificBool , heights);
        bfs(qata , atlanticBool , heights);

        vector<vector<int>>ans;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pacificBool[i][j] == true && atlanticBool[i][j] == true){
                    ans.push_back({i , j});
                }
            }
        }
        return ans;
    }
};