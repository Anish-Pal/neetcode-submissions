class Solution {
public:
    bool isPalindrome(string s) {
       string ans = "";
       for(char ch : s){
         if(isalnum(ch)){
            ans.push_back(tolower(ch));
         }
       }
       int i = 0;
       int j = ans.length() - 1;
       while(i < j){
        if(ans[i] != ans[j]){
            return false;
        }
        i++;
        j--;
       }
       return true;
    }
};
