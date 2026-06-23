class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        int longest = 1;
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    count ++;
                }
                longest = max(longest , count);
            }
        }
        return longest;
    }
};