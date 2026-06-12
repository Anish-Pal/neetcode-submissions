class Solution {
public:

    void solve(vector<int>& candidates , int index , int target , vector<vector<int>>&ans ,vector<int>&temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(index >= candidates.size() || target < 0){
            return;
        }

        temp.push_back(candidates[index]);
        solve(candidates , index , target - candidates[index] , ans , temp);
        temp.pop_back();

        solve(candidates , index+1 , target , ans , temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index = 0;
        solve(candidates , index , target , ans , temp);
        return ans;
    }
};