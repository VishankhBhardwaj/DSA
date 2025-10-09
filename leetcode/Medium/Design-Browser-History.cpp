class BrowserHistory {
public:
    struct ListNode{
        string val;
        ListNode*next;
        ListNode*prev;
        ListNode(string x) : val(x), next(nullptr), prev(nullptr) {}
    };
    ListNode* head;
    ListNode* temp;
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        temp = head;
    }
    
    void visit(string url) {
        ListNode*new_node = new ListNode(url);
        temp->next=new_node;
        new_node->prev=temp;
        temp=temp->next;
    }
    
    string back(int steps) {
        while(temp!=head && steps-->0){
            temp=temp->prev;
        }
        return temp->val;
    }
    
    string forward(int steps) {
        while(temp->next!=nullptr && steps-->0){
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */