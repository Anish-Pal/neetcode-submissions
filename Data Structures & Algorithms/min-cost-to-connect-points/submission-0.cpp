class DisJointSet{
    vector<int>rank ,parent , size;
    public:
        DisJointSet(int n){
            rank.resize(n + 1 , 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for(int i = 0 ; i <= n ; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node ){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionByRank(int u , int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u , int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u]; 
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }   
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int , pair<int , int>>>edges;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int wt = abs(points[i][0] - points[j][0]) + 
                         abs(points[i][1] - points[j][1]);
                edges.push_back({wt , {i , j}});         
            }
        }
        sort(edges.begin() , edges.end());
        int mincst = 0;
        DisJointSet ds(n);
        for(auto it : edges){
            int edgwt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findParent(u) != ds.findParent(v)){
                mincst += edgwt;
                ds.unionBySize(u , v);
            } 
        }
        return mincst;
    }
};
