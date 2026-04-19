class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>pair;
        vector<int>result;
        for(int i = 0 ; i<nums.size(); i++)
        {
            int difference = target - nums[i];
            if(pair.find(difference) != pair.end())
            {
                result.push_back(pair[difference]);
                result.push_back(i);
                return result;
            }
            pair[nums[i]] = i;

        }
        return result;
    }
};
