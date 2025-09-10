class Node{
public:
    int key,val,freq;
    Node*prev;
    Node*next;
    Node(int _key,int _val,int frequency){
        key=_key;
        val=_val;
        freq=frequency;
        next=prev=nullptr;
    }
};
class LFUCache {
public:
    map<int,Node*>mpp;
    int capacity;
    Node*head;
    Node*tail;
    Node*mostFreq;
    LFUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0,0);
        tail=new Node(0,0,0);
        mostFreq=head;
    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* afterNode=node->next;
        afterNode->prev=prevNode;
        prevNode->next=afterNode;
    }
    void insertAfterHead(Node* node){
        Node* currAfterHead=head->next;
        node->next=currAfterHead;
        currAfterHead->prev=node;
        node->prev=head;
        head->next=node;
        mostFreq=node;
    }
    void insertMostRecent(Node*node){
        Node* currAfterHead=mostFreq->next;
        node->next=currAfterHead;
        currAfterHead->prev=node;
        node->prev=mostFreq;
        mostFreq->next=node;
    }
    bool checkMostFreq(Node*node){
        Node*currAfterHead=head->next;
        if(node->freq>currAfterHead->freq) return true;
        else{
            return false;
        }
    }
    
    
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node*node=mpp[key];
        node->freq=node->freq + 1;
        deleteNode(node);
        if(checkMostFreq(node)){
            insertAfterHead(node);
            return node->val;
        }
        insertMostRecent(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        if(mpp.size()==capacity){
            Node*node=tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        Node*new_node=new Node(key,value,1);
        insertMostRecent(new_node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */