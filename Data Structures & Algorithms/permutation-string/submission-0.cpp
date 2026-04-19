class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         vector<int>window(26,0) , need(26,0);
        int n = s1.size();
        int m = s2.size();
        if(n > m){
            return false;
        }
        for(int i = 0 ; i<n ; i++){
            need[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        if(window == need){
            return true;
        }
        for(int i = n ; i < m ; i++){
            window[s2[i]-'a']++;
            window[s2[i-n]-'a']--;

            if(window == need){
                return true;
            }
        }
        return false;
    }
};
