class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int next2 = 0;
        int next1 = 1;
        int curr;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0'){
                curr = 0;
            }
            else{
                curr = next1;
                if(i + 1 < n){
                    if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')){
                        curr += next2;
                    }
                }
            }
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};