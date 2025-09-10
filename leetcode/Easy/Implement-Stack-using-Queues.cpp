class MyStack {
    int arr[1000];
    int rear;
public:
    MyStack() {
        rear=-1;
    }
    
    void push(int x) {
        rear++;
        arr[rear]=x;
    }
    
    int pop() {
        if(rear==-1) return -1;
        int value=arr[rear];
        rear--;
        return value;
    }
    
    int top() {
        if(rear==-1) return -1;
        return arr[rear];
    }
    
    bool empty() {
       return rear==-1; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */