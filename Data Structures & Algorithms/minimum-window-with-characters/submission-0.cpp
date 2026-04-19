class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> mapT;
        if(s.empty() && t.empty() && s.length()<t.length()){
            return "";
        }
        for (char c:t){
            mapT[c]++;
        }
        int required = mapT.size();
        int create = 0;
        int l = 0;
        int len = INT_MAX;
        unordered_map<char,int>windowSub;
        vector<int>ans = {-1,0,0};
        for(int r = 0 ; r<s.size() ; r++){
            char c = s[r];
            windowSub[c]++;

            if(mapT.count(c) && mapT[c] == windowSub[c]){
               create++;
            }
            while(l<=r && create == required){
                if(ans[0]== -1 || ans[0] > r-l+1){
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }
                char leftC = s[l];
                windowSub[leftC]--;
                if(mapT.count(leftC) && windowSub[leftC] < mapT[leftC]){
                    create--;
                }
                l++;
            }
        

        }
        return ans[0] == -1 ? "" : s.substr(ans[1] , ans[0]);
    }
    
};
