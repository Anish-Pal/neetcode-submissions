class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>mp;
        int time = 0;
        priority_queue<int>pq;
        for(char& ch : tasks){
            mp[ch]++;
        }
        for(auto &it : mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            vector<int>ans;
            for(int i = 1 ; i<=n+1 ; i++){
                if(!pq.empty()){
                    ans.push_back(pq.top() - 1);
                    pq.pop();
                }
            }
            for(int& freq : ans){
                if(freq > 0){
                    pq.push(freq);
                }
            }
            if(pq.empty()){
                time += ans.size();
            }
            else{
                time += n + 1;
            }
        }
        return time;
    }
};