class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            freq_map[nums[i]]++;
        }
        int n = nums.size();
        vector<vector<int>>bucket(n+1);
        for(auto it = freq_map.begin() ; it != freq_map.end() ; it++)
        {
           int num = it->first;
           int freq = it->second;
           bucket[freq].push_back(num);
        }

        vector<int> res;
        for(int i = n ; i>0 && res.size() < k ; i--)
        {
            for(int j = 0 ; j<bucket[i].size() ; j++)
            {
                res.push_back(bucket[i][j]);
                if(res.size() == k)   break;  
            }
        }
        return res;
    }
};
