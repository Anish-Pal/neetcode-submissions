class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n + 1 , 1e9);
        vector<pair<int , int>>adj[n + 1];
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v , wt});
        }
        priority_queue<
            pair<int , int>,
            vector<pair<int , int>>,
            greater<pair<int , int>>
            >pq;
        dist[k] = 0;    
        pq.push({0 , k});
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int neighbour = it.first;
                int weight = it.second;
                if(distance + weight < dist[neighbour]){
                    dist[neighbour] = distance + weight;
                    pq.push({dist[neighbour] , neighbour});
                }
            }
        }
        int maxDis = 0;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxDis = max(maxDis , dist[i]);
        }    
        return maxDis;
    }
};