class Solution {
private:
    void bfs(int node , vector<int>&visited , vector<int>adj[]){
        queue<int>q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>visited(n , 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                bfs(i , visited , adj);
                count++;
            }
        }
        return count;
    }
};
