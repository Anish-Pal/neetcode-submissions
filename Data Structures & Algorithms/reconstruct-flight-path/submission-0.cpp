class Solution {
public:
    unordered_map<string , priority_queue<string , vector<string> , greater<string>>>adj;
    vector<string>results;
    void dfs(string airport){
        while(!adj[airport].empty()){
            string nextAirport = adj[airport].top();
            adj[airport].pop();
            dfs(nextAirport);
        }
        results.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &it : tickets){
            string u = it[0];
            string v = it[1];
            adj[u].push(v);
        }
        dfs("JFK");
        reverse(results.begin() , results.end());
        return results;
    }
};