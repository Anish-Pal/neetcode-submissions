class Solution {
public:

    void solve( vector<vector<string>>&ans ,vector<string>&temp , int index , string &s){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i < s.size() ; i++){
            if(isPalindrome(s , index , i)){
                temp.push_back(s.substr(index , i - index + 1));
                solve(ans , temp , i + 1 , s);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s , int low , int high){
        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int index = 0;
        solve(ans , temp , index , s);
        return ans;
    }
};