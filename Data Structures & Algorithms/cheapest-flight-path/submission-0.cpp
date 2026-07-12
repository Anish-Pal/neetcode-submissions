class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n , 1e9);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt  = it[2];
            adj[u].push_back({v , wt});
        }
        queue<pair<int , pair<int , int>>>q; 
        dist[src] = 0;
        q.push({0 , {src , dist[src]}});
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int distance = q.front().second.second;
            q.pop();
            if(steps > k) continue;
            for(auto it : adj[node]){
                int neighbour = it.first;
                int wt = it.second;
                if(distance + wt < dist[neighbour] && steps <= k){
                    dist[neighbour] = distance + wt;
                    q.push({steps + 1 , {neighbour , dist[neighbour]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};