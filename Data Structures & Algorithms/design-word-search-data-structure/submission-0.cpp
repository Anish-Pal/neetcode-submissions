struct Node{
        Node *links[26];
        bool flag = false;
        
        bool containsKey(char ch){
            return(links[ch - 'a'] != NULL);
        }

        void put(char ch , Node* node){
            links[ch - 'a'] = node;
        }
        Node* get(char ch){
            return links[ch - 'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node-> get(word[i]);
        }
        node->setEnd();
    }

    bool searchHelper(Node* node , int index , string word){
        if(index == word.size()){
            return node->isEnd();
        }
        char ch = word[index];
        if(ch != '.'){
            if(!node->containsKey(ch)){
                return false;
            }
            return searchHelper(node->get(ch) , index + 1 , word);
        }
        
        for(int i = 0 ; i < 26 ; i++){
            if(node->links[i] != NULL){
                if(searchHelper(node->links[i] , index + 1 , word)){
                    return true;
                }
            }
        }
        return false;
    }
      
    bool search(string word) {
        return searchHelper(root , 0 , word);
    }
};
