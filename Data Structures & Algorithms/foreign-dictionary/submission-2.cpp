class Solution {
private:
    vector<int>topoSort(unordered_set<int>adj[] , vector<bool>& present){
        int inDegree[26] = {0};
        for(int i = 0 ; i < 26 ; i++){
            for(auto it : adj[i]){
                inDegree[it]++; 
            }
        }
        queue<int>q;
        for(int i = 0 ; i < 26 ; i++){
            if(present[i] && inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }    
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<int>adj[26];
        vector<bool>present(26 , false);
        for(auto word : words){
            for(auto ch : word){
                present[ch - 'a'] = true;
            }
        }
        for(int i = 0 ; i < words.size() - 1 ; i++){
            string s1 = words[i];
            string s2 = words[i + 1];
            if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2){
                return "";
            }
            int len = min(s1.length() , s2.length());
            for(int j  = 0 ; j < len ; j++){
                if(s1[j] != s2[j]){
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].insert(v);
                    break;
                }
            }
        }
        vector<int>topo = topoSort(adj , present);
        
        int total = 0;
        for(int i = 0; i < 26; i++){
            if(present[i]) total++;
        }

        if(topo.size() != total){
            return "";
        }
        string ans = "";
        for(auto it : topo){
            ans = ans + char(it + 'a');
        }
        return ans;
    }
};
