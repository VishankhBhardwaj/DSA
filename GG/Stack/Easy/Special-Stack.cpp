stack<int> minStack;
void push(stack<int>& s, int a) {
    // Your code goes here
    s.push(a);
    if(minStack.empty() || a<=minStack.top()){
        minStack.push(a);
    }
    else {
        minStack.push(minStack.top()); // Push the current min again
    }
    
}

bool isFull(stack<int>& s, int n) {
    // Your code goes here
     return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    // Your code goes here
    return s.empty();
}

int pop(stack<int>& s) {
    // Your code goes here
    int element=s.top();
    s.pop();
    minStack.pop();
    return element;
}

int getMin(stack<int>& s) {
    // Your code goes here
     if (!minStack.empty()) {
        return minStack.top();
    }
    return -1;
}