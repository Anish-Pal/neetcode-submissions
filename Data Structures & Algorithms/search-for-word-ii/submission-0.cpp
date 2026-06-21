class Solution {
public:

    struct Node{
        Node* links[26];
        bool flag = false;
        string word = "";

        Node(){
            for(int i = 0; i < 26; i++){
                links[i] = NULL;
            }
        }

        bool containsKey(char ch){
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, Node* node){
            links[ch - 'a'] = node;
        }

        Node* get(char ch){
            return links[ch - 'a'];
        }

        void setEnd(string s){
            flag = true;
            word = s;
        }
    };

    Node* root = new Node();

    void insert(string word){
        Node* node = root;

        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }

        node->setEnd(word);
    }

    void solve(vector<vector<char>>& board,
               int row,
               int col,
               Node* node,
               vector<string>& ans){

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()){
            return;
        }

        char ch = board[row][col];

        if(ch == '#')
            return;

        if(!node->containsKey(ch))
            return;

        node = node->get(ch);

        if(node->flag){
            ans.push_back(node->word);

            // avoid duplicate answers
            node->flag = false;
        }

        board[row][col] = '#';

        solve(board,row+1,col,node,ans);
        solve(board,row-1,col,node,ans);
        solve(board,row,col+1,node,ans);
        solve(board,row,col-1,node,ans);

        board[row][col] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for(string word : words){
            insert(word);
        }

        vector<string> ans;

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                solve(board,i,j,root,ans);
            }
        }

        return ans;
    }
};