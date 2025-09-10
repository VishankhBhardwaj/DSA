class MinStack {
    stack<int>st;
    stack<int>Minst;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(Minst.empty() || val<=Minst.top()){
            Minst.push(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        if(st.top()==Minst.top()){
            Minst.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(Minst.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return Minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */