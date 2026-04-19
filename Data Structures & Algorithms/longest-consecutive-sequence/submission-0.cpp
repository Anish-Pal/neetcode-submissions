class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numset(nums.begin() , nums.end());
        int longest = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int num = nums[i];

            if(numset.find(num - 1) == numset.end()){
                int cst = 1;
                int currentNum = num;

                while(numset.find(currentNum + 1) != numset.end()){
                    currentNum += 1;
                    cst += 1;
                }
                longest = max(longest , cst);
            }
        }
        return longest;
    }
};
