class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* head;
    MyLinkedList() { head = NULL; }

    int get(int index) {
        ListNode* ptr = head;
        int i = 0;
        while (ptr != nullptr && i < index) {
            ptr = ptr->next;
            i++;
        }
        if (ptr == nullptr)
            return -1;
        return ptr->val;
    }

    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        head = new_node;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* ptr = head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode* ptr = head;
        int i = 0;
        while (ptr != nullptr && i < index - 1) {
            ptr = ptr->next;
            i++;
        }
        if (ptr == nullptr)
            return;
        ListNode* new_node = new ListNode(val);
        new_node->next = ptr->next;
        ptr->next = new_node;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr)
            return;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* ptr = head;
        int i = 0;
        while (ptr->next != nullptr && i < index - 1) {
            ptr = ptr->next;
            i++;
        }
        if (ptr->next == nullptr)
            return;
        ListNode* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */