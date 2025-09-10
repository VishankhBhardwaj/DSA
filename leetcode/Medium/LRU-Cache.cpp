class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = next = nullptr;
    }
};
class LRUCache {
public:
    map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;
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
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node*node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node*node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size()==capacity){
                Node*node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node*new_Node=new Node(key,value);
            mpp[key]=new_Node;
            insertAfterHead(new_Node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */