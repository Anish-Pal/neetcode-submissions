class LRUCache {
public:
    
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    void deletionNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    void insertAfterHead(Node* node){
        Node* currAfterhead = head->next;
        head->next = node;
        node->next = currAfterhead;
        node->prev = head;
        currAfterhead->prev = node;
    }

    int cap;
    unordered_map<int , Node*>mpp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        Node* node = mpp[key];
        deletionNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deletionNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deletionNode(node);
            }
            Node* node = new Node(key , value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

