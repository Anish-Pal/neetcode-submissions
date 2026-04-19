class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0 ; i<strs.size() ; i++){
            string s = strs[i];
            encoded += to_string(s.length()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i = 0;
        while(i<s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            string decode = s.substr(i,j-i);
            int length = stoi(decode);

            string p = s.substr(j+1,length);
            decoded.push_back(p);

            i = j + 1 + length;
        }
        return decoded;
    }
};
