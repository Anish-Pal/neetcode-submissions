class Solution {
public:
    
    void solve(string digits ,vector<string>&ans , string output , int index , string map[]){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string temp = map[number];
        for(int i = 0 ; i < temp.size() ; i++){
            output.push_back(temp[i]);
            solve(digits , ans , output , index + 1 , map);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output = "";
        if(digits.size() == 0){
            return ans;
        }
        string map[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        solve(digits , ans , output , index , map);
        return ans;
    }
};