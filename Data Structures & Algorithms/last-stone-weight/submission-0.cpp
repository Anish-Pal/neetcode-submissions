class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int num : stones){
            pq.push(num);
        }
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int dif;
            if(x != y){
                dif = x - y;
                pq.push(dif);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
