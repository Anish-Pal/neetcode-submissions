class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>hash1;
        unordered_map<int,int>hash2;
        if(s.size() != t.size())
        {
            return false;
        }
        for(int i = 0 ; i<s.size(); i++)
        {
           hash1[s[i]-'a']++;
        }
        for(int i = 0 ; i<s.size(); i++)
        {
           hash2[t[i]-'a']++;
        }
       if(hash1 == hash2 )
       {
        return true;
       }
       return false;
    }
};
