class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= n-1){
            return false;
        }
        vector<int>adj[n];
        vector<int>visited(n , 0);
        queue<int>q;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        q.push(0);
        visited[0] = 1;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        if(count != n){
            return false;
        }
        return true;
    }
};
