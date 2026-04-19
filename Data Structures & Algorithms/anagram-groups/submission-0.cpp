class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mpp;
       for(int i = 0 ; i<strs.size() ; i++)
       {
        string str = strs[i];
        vector<int>hash(26,0);
        for(int j = 0 ; j<str.size(); j++)
        {
            char c = str[j];
            hash[c-'a']++;
        }
         string key = "";
         for(int k = 0 ; k< hash.size(); k++)
         {
            key += to_string(hash[k]) + "#";
         }
         mpp[key].push_back(str);
       }

        vector<vector<string>> res;

       for(auto it = mpp.begin() ; it != mpp.end() ; it++)
       {
         vector<string>& anagramgrp = it->second;
         res.push_back(anagramgrp);
       }
       return res;
    }
};
