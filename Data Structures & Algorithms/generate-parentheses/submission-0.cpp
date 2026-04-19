class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res , "" , 0 , 0 , n);
        return res;
    }
void backtrack(vector<string>& ans,string curr,int open,int close,int n){
      if(curr.size() == 2*n){
        ans.push_back(curr);
        return;
      }
      if(open < n){
         backtrack(ans , curr + '(' , open+1 , close , n);
      }
      if(close < open){
        backtrack(ans , curr + ')' , open , close+1 , n);
      }

  }
};