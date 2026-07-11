class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n , vector<int>(n , 1e9));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int , pair<int,int>>>,
            greater<pair<int , pair<int,int>>>
            >pq;
        pq.push({grid[0][0] , {0 , 0}});
        dist[0][0] = grid[0][0];    
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(time > dist[row][col]){
                continue;
            }
            if(row == n-1 && col == n-1){
                return time;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nr = dr[i] + row;
                int nc = dc[i] + col;
                if(nr >= 0 && nr < n && nc >=0 && nc < n){
                    int newTime = max(time , grid[nr][nc]);
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime;
                        pq.push({newTime , {nr , nc}});
                    }
                }
            }
        }
        return -1;
    }
};