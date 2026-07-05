class Solution {
private:
    bool bfs(int u , int v , vector<int>adj[] , vector<int>visited){
        queue<int>q;
        q.push(u);
        visited[u] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    if(it == v){
                        return true;
                    }
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return false;
    }    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adj[n+1];
        vector<int>visited(n+1 , 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(bfs(u , v , adj , visited)){
                return {u , v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};