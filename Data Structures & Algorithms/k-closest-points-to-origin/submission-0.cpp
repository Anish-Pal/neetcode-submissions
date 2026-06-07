class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int x_org = 0;
        int y_org = 0;
        priority_queue<pair<int, vector<int>>> pq;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            x = x - x_org;
            x = x*x;
            y = y - y_org;
            y = y*y;
            int dis = x + y;
            pq.push({dis , point});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};