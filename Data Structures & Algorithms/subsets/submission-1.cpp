class Solution {
public:

    void solve(vector<int> nums, int index , vector<int>&temp ,vector<vector<int>>&output){
        if(index >= nums.size()){
            output.push_back(temp);
            return;
        }

        solve(nums , index+1 , temp , output);

        temp.push_back(nums[index]);
        // temp.pop_back();
        solve(nums , index+1 , temp , output);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output;
        vector<int>temp;
        int index = 0;
        solve(nums , index , temp , output);

        return output;
    }
};